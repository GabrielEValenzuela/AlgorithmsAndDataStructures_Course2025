#include "engineData.hpp"
#include "randomEventGenerator.hpp"

#include <memory>

class VisitorFactory
{
public:
    explicit VisitorFactory(RandomEventGenerator& rng);
    VisitanteVariant create(EngineData::Faction faction);

private:
    std::shared_ptr<RandomEventGenerator> m_rng;
};
