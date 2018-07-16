


//https://godbolt.org/g/VP3KJ4
namespace crtp
{


template< typename T >
class Interface
{
public:
  void Tick()
  {
    derived().Tick();
  }

  int GetValue() const
  {
    return derived().GetValue();
  }

  void SumUp()
  {
    derived().SumUp();
  }

private:
  inline T& derived()
  {
    return static_cast< T& >( *this );
  }
};

class Implementation : public Interface< Implementation >
{
public:
  void Tick()
  {
    ++m_value;
  }

  int GetValue() const
  {
    return m_value;
  }

  void SumUp()
  {
    m_sum += GetValue();
  }

private:
  int m_value = 0;
  int m_sum = 0;
};

}
