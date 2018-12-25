

#include "OpenServerCommand.h"
vector<double> explode1(string &s, const char &c)
{

    string buff{""};
    vector<double> v;
    for (auto n:s) {
        if (n != c) {
            buff += n;
        } else if(buff != ""){
            double num;
            num = stod(buff);
            v.push_back(num);
            buff = "";
        }
    }
    return v;
}

void* serverThread(void *arg) {
    int port = serverParams.port;
    int rate = serverParams.rate;
    cout << "here2" << endl;
    vector<string> xmlVal;
    xmlVal.push_back("/instrumentation/airspeed-indicator/indicated-speed-kt");
    xmlVal.push_back("/instrumentation/altimeter/indicated-altitude-ft");
    xmlVal.push_back("/instrumentation/altimeter/pressure-alt-ft");
    xmlVal.push_back("/instrumentation/attitude-indicator/indicated-pitch-deg");
    xmlVal.push_back("/instrumentation/attitude-indicator/indicated-roll-deg");
    xmlVal.push_back("/instrumentation/attitude-indicator/internal-pitch-deg");
    xmlVal.push_back("/instrumentation/attitude-indicator/internal-roll-deg");
    xmlVal.push_back("/instrumentation/encoder/indicated-altitude-ft");
    xmlVal.push_back("/instrumentation/encoder/pressure-alt-ft");
    xmlVal.push_back("/instrumentation/gps/indicated-altitude-ft");
    xmlVal.push_back("/instrumentation/gps/indicated-ground-speed-kt");
    xmlVal.push_back("/instrumentation/gps/indicated-vertical-speed</node>");
    xmlVal.push_back("/instrumentation/heading-indicator/indicated-heading-deg");
    xmlVal.push_back("/instrumentation/magnetic-compass/indicated-heading-deg");
    xmlVal.push_back("/instrumentation/slip-skid-ball/indicated-slip-skid");
    xmlVal.push_back("/instrumentation/turn-indicator/indicated-turn-rate");
    xmlVal.push_back("/instrumentation/vertical-speed-indicator/indicated-speed-fpm");
    xmlVal.push_back("/controls/flight/aileron");
    xmlVal.push_back("controls/flight/rudder");
    xmlVal.push_back("controls/flight/flaps");
    xmlVal.push_back("controls/engines/current-engine/throttle");
    xmlVal.push_back("/engines/engine/rpm");

    vector<double> ve;
    int sockfd, newsockfd, clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int n;
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    // Now bind the host address using bind() call.
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Now start listening for the clients, here process will
     //  go in sleep mode and will wait for the incoming connection


    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Accept actual connection from the client
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    serverParams.move = true;
    cout << "connected" << endl;
    //If connection is established then start communicating
    while (serverParams.move) {
        pthread_mutex_lock(&mutexXml);
        clock_t time_start;
        time_start = clock();

        bzero(buffer, 1024);
        n = read(newsockfd, buffer, 1023);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        string buf = buffer;
        ve = explode1(buf, ',');
        if(ve.size() > 23){
            int i = 0;
            int size = buf.find("\n");
            buf.erase(0,size +1);
            size =  buf.find("\n");
            buf.erase(size,buf.size() +1);
            ve = explode1(buf, ',');
        }
        int size = xmlVal.size();
        for (int i = 0; i <size ; ++i) {
            xmlTable[xmlVal.at(i)] = ve.at(i);
        }
        buf = "";

        /*
        for (auto it = xmlTable.begin(); it != xmlTable.end(); ++it) {
            it.operator*().second = ve.at(i);
            i++;
        }*/
        clock_t time_end;
        time_end = time_start + 10 * rate * CLOCKS_PER_SEC / 1000;
       pthread_mutex_unlock(&mutexXml);
        while (clock() < time_end) {}

    }
    pthread_mutex_destroy(&mutexXml);
    pthread_mutex_destroy(&mutexIns);
    close(sockfd);
}

int OpenServerCommand::doCommand(vector<string> &x){
    int num0 = 0;
    int num1 = 0;

    try {
        num0 = stoi(x.at(0));
        num1 = stoi(x.at(1));
    } catch (invalid_argument &exception1){
        throw "illegal arguments";
    }

    //ServerParams params;
    serverParams.port = num0;
    serverParams.rate = num1;

    pthread_t trid;
    pthread_create(&trid, nullptr, serverThread, nullptr);

    while (!serverParams.move) {}

    return 2;

}




