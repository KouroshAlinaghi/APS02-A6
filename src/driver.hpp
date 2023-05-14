#ifndef DRIVER_HEADERFILE
#define DRIVER_HEADERFILE

class Driver {
private:
    int id;
public:
    Driver(int id_) {
        id = id_;
    }
    int get_id();
};

#endif