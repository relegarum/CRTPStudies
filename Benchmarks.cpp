#include <benchmark/benchmark.h>

#include <memory>
#include "BenchmarkCrtp.h"
#include "BenchmarkVirtual.h"

static void BM_CRTP( benchmark::State& state )
{
  auto crtpImpl = std::make_unique< crtp::Implementation >();
  for( auto _ : state )
  {
    crtpImpl->Tick();
    crtpImpl->SumUp();
    benchmark::DoNotOptimize( crtpImpl->GetValue() );
  }

}

BENCHMARK( BM_CRTP );

static void BM_Virtual( benchmark::State& state )
{
  auto virtualImpl = std::make_unique< dynamic::Implementation >();
  for( auto _ : state )
  {
    virtualImpl->Tick();
    virtualImpl->SumUp();
    benchmark::DoNotOptimize( virtualImpl->GetValue() );
  }

  volatile const auto value = virtualImpl->GetValue();
}

BENCHMARK( BM_Virtual );

BENCHMARK_MAIN();
