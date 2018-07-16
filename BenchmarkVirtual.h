

// https://godbolt.org/g/tQ9GPk
namespace dynamic
{

class Interface
{
public:
  virtual void Tick() = 0;
  virtual int GetValue() const = 0;
  virtual void SumUp() = 0;
};


class Implementation : public Interface 
{
public:
  void Tick() override
  {
    ++m_value;
  }

  int GetValue() const override
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
