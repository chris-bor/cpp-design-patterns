#pragma once

// Adding/deleting new methods is simpler to existing hierarchy but adding/deleting new classes is more complicated.

namespace cyclicvisitor {

class Unit;
class Infantry;
class Tank;
class Rocket;

class Visitator {
public:
    virtual ~Visitator(){}
    virtual void visit(Infantry &) = 0;
    virtual void visit(Tank &) = 0;
    virtual void visit(Rocket &) = 0;
};

class Unit {
public:
    virtual ~Unit(){}
    virtual void accept(Visitator &v) = 0;
};

class Infantry : public Unit {
public:
    virtual ~Infantry(){}
    virtual void accept(Visitator &v) { v.visit(*this); }
    void addSoldiers(int n) { mSoldiers += n; }
    int getSoldiers() const { return mSoldiers; }
private:
    int mSoldiers{0};
};

class Tank : public Unit {
public:
    virtual ~Tank(){}
    virtual void accept(Visitator &v) { v.visit(*this); }
    void addTanks(int n) { mTanks += n; }
    int getTanks() const { return mTanks; }
private:
    int mTanks{0};
};

class Rocket : public Unit {
public:
    virtual ~Rocket(){}
    virtual void accept(Visitator &v) { v.visit(*this); }
    void addRockets(int n) { mRockets += n; }
    int getRockets() const { return mRockets; }
private:
    int mRockets{0};
};

class Statistics : public Visitator {
public:
    virtual void visit(Infantry &u) { mSoldiers += u.getSoldiers(); }
    virtual void visit(Tank &u) { mTanks += u.getTanks(); }
    virtual void visit(Rocket &u) { mRockets += u.getRockets(); }
    int soldiers() const {return mSoldiers; }
    int tanks() const {return mTanks; }
    int rockets() const {return mRockets; }
private:
    int mSoldiers{0};
    int mTanks{0};
    int mRockets{0};
};


}
