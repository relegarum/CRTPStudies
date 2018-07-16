



template< typename T >
class Base
{
  // ...
};

class Derived : public Base< Derived >
{
  // ...
};

class Derived2 : public Base< Derived > // <-- UNDEFINED BEHAVIOR
{
  // ...
};
