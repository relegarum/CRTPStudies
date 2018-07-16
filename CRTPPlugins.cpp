




template< typename T >
class NumericalFunctions
{
public:
  void Scale( double multiplier )
  {
    auto& underlying = static_cast< T& >( *this );
    underlying.SetValue( underlying.GetValue() * multiplier );
  }

  void SetToOpposite()
  {
    Scale( -1 );
  }

private:
  NumericalFunctions() = default;
  friend T;
};

template< typename T >
class Functionals
{
public:
  template< class Callable >
  double Apply( Callable& callable )
  {
    return callable( static_cast< T& >( *this ).GetValue() );
  }

private:
  Functionals() = default;
  friend T;
};

class Valuable : public NumericalFunctions< Valuable >,
                 public Functionals< Valuable >
{
public:
  double GetValue() const
  {
    return m_value;
  }

  void SetValue( const double value )
  {
    m_value = value;
  }

private:
  double m_value;
};
                   
