//
// Created by noam on 1/17/19.
//

#ifndef EVEN2_CLIENTHANDLER_H
#define EVEN2_CLIENTHANDLER_H


class ClientHandler {
public:
    virtual void handleClient(int socketNumber)=0;
};


#endif //EVEN2_CLIENTHANDLER_H
