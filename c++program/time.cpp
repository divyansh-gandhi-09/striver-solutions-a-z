#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Base Timer class
class Timer {
protected:
    // Store start and end points in time
    steady_clock::time_point start_time;
    steady_clock::time_point end_time;
    bool running; // To check if the timer is currently running

public:
    Timer() : running(false) {}

    // Virtual functions to be overridden by derived classes
    virtual void start() {
        start_time = steady_clock::now();
        running = true;
    }

    virtual void stop() {
        end_time = steady_clock::now();
        running = false;
    }

    virtual void reset() = 0;
    virtual void display() const = 0;

    // Function to calculate elapsed time in milliseconds
    long long elapsedMilliseconds() const {
        auto end = running ? steady_clock::now() : end_time;
        return duration_cast<milliseconds>(end - start_time).count();
    }
};

// Derived Stopwatch class
class Stopwatch : public Timer {
public:
    // Reset overrides Timer's reset
    void reset() override {
        start_time = steady_clock::now();
        end_time = start_time;
        running = false;
    }

    // Display function to show elapsed time in hours, minutes, seconds, and milliseconds
    void display() const override {
        long long ms = elapsedMilliseconds();
        long long hours = ms / 3600000;
        ms %= 3600000;
        long long minutes = ms / 60000;
        ms %= 60000;
        long long seconds = ms / 1000;
        ms %= 1000;

        cout << "Elapsed time: "
             << setfill('0') << setw(2) << hours << ":"
             << setw(2) << minutes << ":"
             << setw(2) << seconds << "."
             << setw(3) << ms << endl;
    }
};
int main() {
    Stopwatch stopwatch;
    char choice;

    cout << "Simple Stopwatch Application" << endl;
    cout << "Commands:\n"
         << "s - Start\n"
         << "e - Stop\n"
         << "r - Reset\n"
         << "d - Display\n"
         << "q - Quit" << endl;

    do {
        cout << "\nEnter command: ";
        cin >> choice;

        switch (choice) {
            case 's':
                stopwatch.start();
                cout << "Stopwatch started." << endl;
                break;

            case 'e':
                stopwatch.stop();
                cout << "Stopwatch stopped." << endl;
                break;

            case 'r':
                stopwatch.reset();
                cout << "Stopwatch reset." << endl;
                break;

            case 'd':
                stopwatch.display();
                break;

            case 'q':
                cout << "Exiting stopwatch." << endl;
                break;

            default:
                cout << "Invalid command. Please try again." << endl;
        }
    } while (choice != 'q');

    return 0;
}