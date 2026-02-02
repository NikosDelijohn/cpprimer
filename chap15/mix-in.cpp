#include <iostream>
#include <string>

// -------------------------------------------------
// 1) Common root interface (the "core" of the system)
// -------------------------------------------------
struct Application
{
    // Virtual destructor because we will use polymorphism
    virtual ~Application() = default;

    // Interface that all applications must implement
    virtual void init() = 0;
    virtual void run()  = 0;
};

// -------------------------------------------------
// 2) First mixin: adds logging behavior
// -------------------------------------------------
// "virtual" inheritance is used so that if many mixins
// derive from Application, there will be only ONE shared
// Application subobject in the final class.
struct LoggingMixin : public virtual Application
{
    // Override part of the interface
    void init() override {
        std::cout << "[LoggingMixin] init()\n";
    }

    // New functionality added by this mixin
    void log(const std::string& msg) const {
        std::cout << "[LOG] " << msg << "\n";
    }
};

// -------------------------------------------------
// 3) Second mixin: adds timing / profiling behavior
// -------------------------------------------------
struct TimingMixin : public virtual Application
{
    // Override part of the interface
    void run() override {
        std::cout << "[TimingMixin] run() timing started\n";
    }
};

// -------------------------------------------------
// 4) Concrete class that *combines* the mixins
// -------------------------------------------------
// This class represents the "real" application.
// It inherits behavior from multiple mixins.
struct MyApp : public LoggingMixin, public TimingMixin
{
    // Because both mixins override Application::init(),
    // we provide the final override here and decide how
    // the behaviors are composed.
    void init() override {
        LoggingMixin::init();            // call mixin behavior
        std::cout << "[MyApp] init()\n"; // add own behavior
    }

    // Same for run()
    void run() override {
        TimingMixin::run();              // call mixin behavior
        std::cout << "[MyApp] run()\n";  // add own behavior
    }
};

// -------------------------------------------------
// 5) Usage
// -------------------------------------------------
int main()
{
    MyApp app;

    // View the object through the common base interface.
    // Because of virtual inheritance, there is exactly ONE
    // Application subobject shared by all mixins.
    Application& base = app;

    base.init();   // dynamic dispatch → MyApp::init()
    base.run();    // dynamic dispatch → MyApp::run()

    // We can also access mixin-specific functionality
    app.log("Hello from the LoggingMixin!");

    return 0;
}
