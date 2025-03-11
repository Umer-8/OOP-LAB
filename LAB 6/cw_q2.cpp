#include <iostream>
#include <string>
using namespace std;

class Mediafile {
protected:
    string path;
    int size;

public:
    Mediafile(const string& p, int s) : path(p), size(s) {}

    virtual void play() const {
        cout << "Playing media file: " << path << " (Size: " << size << " KB)" << endl;
    }

    virtual void stop() const {
        cout << "Stopping media file: " << path << endl;
    }

    virtual ~Mediafile() {}
};

class Visualmedia : virtual public Mediafile {
protected:
    string resolution;

public:
    Visualmedia(const string& p, int s, const string& res)
        : Mediafile(p, s), resolution(res) {}

    void displayResolution() const {
        cout << "Resolution: " << resolution << endl;
    }
};

class Audiomedia : virtual public Mediafile {
protected:
    int sample_rate;

public:
    Audiomedia(const string& p, int s, int rate)
        : Mediafile(p, s), sample_rate(rate) {}

    void displaySampleRate() const {
        cout << "Sample Rate: " << sample_rate << " Hz" << endl;
    }
};

class Videofile : public Visualmedia, public Audiomedia {
public:
    Videofile(const string& p, int s, const string& res, int rate)
        : Mediafile(p, s), Visualmedia(p, s, res), Audiomedia(p, s, rate) {}

    void play() const override {
        cout << "Playing video file: " << path << endl;
        displayResolution();
        displaySampleRate();
    }

    void stop() const override {
        cout << "Stopping video file: " << path << endl;
    }
};

class Imagefile : public Visualmedia {
public:
    Imagefile(const string& p, int s, const string& res)
        : Mediafile(p, s), Visualmedia(p, s, res) {}

    void play() const override {
        cout << "Displaying image file: " << path << endl;
        displayResolution();
    }

    void stop() const override {
        cout << "Stopping image file: " << path << endl;
    }
};

class Audiofile : public Audiomedia {
public:
    Audiofile(const string& p, int s, int rate)
        : Mediafile(p, s), Audiomedia(p, s, rate) {}

    void play() const override {
        cout << "Playing audio file: " << path << endl;
        displaySampleRate();
    }

    void stop() const override {
        cout << "Stopping audio file: " << path << endl;
    }
};

int main() {
    Videofile video("video.mp4", 1024, "1080p", 44100);
    Imagefile image("image.jpg", 512, "720p");
    Audiofile audio("audio.mp3", 256, 48000);

    Mediafile* mediaFiles[] = { &video, &image, &audio };

    for (Mediafile* media : mediaFiles)
    {
        media->play();
        media->stop();
        cout << endl;
    }
    return 0;
}