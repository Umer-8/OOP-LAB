#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <typeinfo>
#include <exception>

using namespace std;

class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "BadTypeException: Type mismatch during retrieval.";
    }
};

class BaseHolder {
public:
    virtual ~BaseHolder() = default;
    virtual const type_info& type() const = 0;
    virtual unique_ptr<BaseHolder> clone() const = 0;
};

template<typename T>
class Holder : public BaseHolder {
public:
    T value;
    Holder(const T& v) : value(v) {}
    const type_info& type() const override {
        return typeid(T);
    }
    unique_ptr<BaseHolder> clone() const override {
        return make_unique<Holder<T>>(value);
    }
};

class TypeSafeContainer {
private:
    unordered_map<string, unique_ptr<BaseHolder>> data;

public:
    template<typename T>
    void store(const string& key, const T& value) {
        data[key] = make_unique<Holder<T>>(value);
    }

    template<typename T>
    T get(const string& key) const {
        auto it = data.find(key);
        if (it == data.end()) {
            throw out_of_range("Key not found.");
        }
        if (it->second->type() != typeid(T)) {
            throw BadTypeException();
        }
        return static_cast<Holder<T>*>(it->second.get())->value;
    }
};

int main() {
    TypeSafeContainer container;

    container.store("x", 100);
    container.store("pi", 3.14);
    container.store("name", string("TypeSafe"));
    container.store("ok", true);

    try {
        cout << "x: " << container.get<int>("x") << "\n";
        cout << "pi: " << container.get<double>("pi") << "\n";
        cout << "name: " << container.get<string>("name") << "\n";
        cout << "ok: " << boolalpha << container.get<bool>("ok") << "\n";
        container.get<string>("x");
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}
