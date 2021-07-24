#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
    public:
        GameObject() = default;
        virtual void Update() =0;
        virtual void Render() =0;
        ~GameObject(void) = default;
};

#endif