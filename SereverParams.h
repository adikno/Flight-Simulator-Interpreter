

#ifndef UNTITLED9_SEREVERPARAMS_H
#define UNTITLED9_SEREVERPARAMS_H

class ServerParams {
    int port;
    int rate;
public:
    ServerParams(){

    }

    int getPort() {
        return this->port;
    }

    int getRate() {
        return this->rate;
    }
    void setPort(int x){
        this->port = x;
    }
    void setRate(int x){
        this->rate = x;
    }
};

#endif //UNTITLED9_SEREVERPARAMS_H
