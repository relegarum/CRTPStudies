



template< typename T >
class Base
{
  // ...
private:
  Base();
  friend T;
};

class Derived : public Base< Derived >
{
  // ...

};

class Derived2 : public Base< Derived > // <-- Compile error
{
  // ...
};
