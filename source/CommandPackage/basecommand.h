#ifndef BASECOMMAND_H
#define BASECOMMAND_H

// Basic class of the Command

// When inheriting, to customize the parameter of the command
// Can change the Constructor
// To have different input parameters

class BaseCommand
{

public:    
    BaseCommand();
    virtual ~BaseCommand();

    // The execution shall be implemented by all inherit leaf classes
    virtual void executeCommand();


};

#endif // BASECOMMAND_H
