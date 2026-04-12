#ifndef BASEPROPERTYCOMP_H
#define BASEPROPERTYCOMP_H

// shall think about, the object status shall be here, or make this
// class pure virtual, and move those status lists into others Property component

// decided, make this pure virtual -- 10.8.2023
// and put properties into this childern. -- 04.11.2026

class BasePropertyComp
{

public:
    BasePropertyComp();
    virtual ~BasePropertyComp();

    virtual void updateProperty();

private:
};

#endif // BASEPROPERTYCOMP_H
