#pragma once

class Message {
public:
    enum Type {
        MOUSE_INPUT
    };

    Message(Type type);

    Type type_;
private:

};
