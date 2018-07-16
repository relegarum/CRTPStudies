



class Base
{
public:
  void DoSomethingComplex()
  {
    doSomethingSimpler();
    doOtherThingSimpler();
  }

protected:
  virtual void doSomethingSimpler() = 0;
  virtual void doOtherThingSimpler() = 0;
};

class Derived : public Base
{
private:
  void doSomethingSimpler() override
  {
    // ...
  }

  void doOtherThingSimpler() override
  {
    // ...
  }
};
