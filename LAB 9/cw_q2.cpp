#include <iostream>
#include <vector>
#include <string>

const int LOG_INFO = 0;
const int LOG_WARNING = 1;
const int LOG_ERROR = 2;

using namespace std;

class Auditor {
string name;
bool authenticated;

public:
Auditor(const string& name, bool authenticated = false)
: name(name), authenticated(authenticated) {}

bool isAuthenticated() const { return authenticated; }
const string& getName() const { return name; }
};

class Logger {
private:
struct LogEntry {
string timestamp;
string module;
int severity;
string message;
};

vector<LogEntry> logs;
size_t maxLogs;
static const size_t DEFAULT_MAX_LOGS = 1000;

string getCurrentTime() {
    return "[timestamp]";
}

void addLog(const string& module, int severity, const string& message) {
    if (logs.size() >= maxLogs) {
        logs.erase(logs.begin());
    }
    logs.push_back({getCurrentTime(), module, severity, message});
}

string severityToString(int severity) const {
    if (severity == LOG_INFO) return "INFO";
    if (severity == LOG_WARNING) return "WARNING";
    if (severity == LOG_ERROR) return "ERROR";
    return "UNKNOWN";
}
public:
Logger(size_t maxLogs = DEFAULT_MAX_LOGS) : maxLogs(maxLogs) {
if (maxLogs == 0) {
maxLogs = DEFAULT_MAX_LOGS;
}
}

void logInfo(const string& module, const string& message) {
    addLog(module, LOG_INFO, message);
}

void logWarning(const string& module, const string& message) {
    addLog(module, LOG_WARNING, message);
}

void logError(const string& module, const string& message) {
    addLog(module, LOG_ERROR, message);
}

void log(const string& module, int severity, const string& message) {
    addLog(module, severity, message);
}

vector<string> getLogs(const Auditor& auditor) const {
    if (!auditor.isAuthenticated()) {
        cerr << "Unauthorized access attempt by " << auditor.getName() << "\n";
        return {};
    }

    vector<string> formattedLogs;
    for (size_t i = 0; i < logs.size(); i++) {
        const LogEntry& entry = logs[i];
        formattedLogs.push_back(
            entry.timestamp + " " + 
            "[" + entry.module + "] " + 
            "[" + severityToString(entry.severity) + "] " + 
            entry.message
        );
    }

    return formattedLogs;
}

vector<string> getRecentLogs(size_t count) const {
    if (count == 0 || count > logs.size()) {
        count = logs.size();
    }

    vector<string> recentLogs;
    size_t start = logs.size() - count;
    for (size_t i = start; i < logs.size(); i++) {
        const LogEntry& entry = logs[i];
        recentLogs.push_back(
            entry.timestamp + " " + 
            "[" + entry.module + "] " + 
            "[" + severityToString(entry.severity) + "] " + 
            entry.message
        );
    }

    return recentLogs;
}

size_t getLogCount() const {
    return logs.size();
}
};

int main() {
Logger logger(5);

logger.logInfo("Network Module", "Connection established");
logger.logWarning("Database Module", "Connection timeout, retrying...");
logger.logError("Authentication Module", "Invalid credentials");
logger.logInfo("Network Module", "Data packet received");
logger.logWarning("Database Module", "Query took longer than expected");
logger.logInfo("System Module", "Maintenance task completed");

cout << "Recent logs (" << logger.getLogCount() << " entries):\n";
vector<string> recentLogs = logger.getRecentLogs(5);
for (size_t i = 0; i < recentLogs.size(); i++) {
    cout << recentLogs[i] << "\n";
}

Auditor unauthorized("Bob");
Auditor authorized("Alice", true);

vector<string> unauthorizedLogs = logger.getLogs(unauthorized);
if (unauthorizedLogs.empty()) {
    cout << "\nUnauthorized access correctly prevented\n";
}

cout << "\nAudit logs for " << authorized.getName() << ":\n";
vector<string> auditLogs = logger.getLogs(authorized);
for (size_t i = 0; i < auditLogs.size(); i++) {
    cout << auditLogs[i] << "\n";
}

return 0;
}