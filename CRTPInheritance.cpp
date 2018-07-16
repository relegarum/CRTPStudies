



template< typename T >
class Base
{
public:
  void DoSomethingComplex()
  {
    underlying().doSomethingSimpler();
    underlying().doOtherThingSimpler();
  }

private:
  T& underlying()
  {
    return static_cast< T& >( *this );
  }
};

class Derived : public Base< Derived >
{
private:
  void doSomethingSimpler()
  {
    // ...
  }

  void doOtherThingSimpler()
  {
    // ...
  }
};
