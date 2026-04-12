#include "landpropertycomp.h"

LandPropertyComp::LandPropertyComp():
    statusOnObject_(0),
    statusInsideObject_(0),
    statusBelowObject_(0),
    state_(0),
    height_(200),
    width_(200){}

void LandPropertyComp::setDefaultHeight(void) {
    this->height_ = 200;
}

void LandPropertyComp::setDefaultWidth(void) {
    this->width_ = 200;
}

int LandPropertyComp::getWidth(void) const
{
    return this->width_;
}

int LandPropertyComp::getHeight(void) const
{
    return this->height_;
}

void LandPropertyComp::setWidth(int width) {
    this->width_ = width;
}
void LandPropertyComp::setHeight(int height) {
    this->height_ = height;
}
