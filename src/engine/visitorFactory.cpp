#include "engine/visitorFactory.hpp"
#include "asaltante.hpp"
#include "caravana.hpp"

#include <functional>
#include <unordered_map>

const std::vector<std::string> VisitorFactory::NAMES = {
    "Lucas", "Valentina", "Mateo",  "Camila",   "Santiago", "Julieta", "Benjamín", "Martina", "Joaquín", "Catalina",
    "Tomás", "Emma",      "Franco", "Isabella", "Thiago",   "Renata",  "Ignacio",  "Mía",     "Bruno",   "Lola"};

const std::vector<std::string> VisitorFactory::SURNAMES = {
    "Fernández", "Gómez", "Rodríguez", "López",  "Martínez", "Pérez", "González", "Romero", "Sosa",   "Torres",
    "Álvarez",   "Ruiz",  "Ramírez",   "Flores", "Acosta",   "Ortiz", "Silva",    "Molina", "Castro", "Núñez"};

const std::vector<std::string> VisitorFactory::GROUPS_ENEMIES = {
    "El Lince", "Cuchillo", "Sombra", "Rata",  "Machete", "El Tuerto", "Ruger",  "Veneno", "Kilo",    "Toro",
    "Jaque",    "Hueso",    "Chispa", "Ruido", "Filo",    "El Ciego",  "Piedra", "Trapo",  "Garrote", "Ladrido"};

const std::vector<std::string> VisitorFactory::MERCHANTS = {"Don Eric",       "El turco",
                                                            "El Sapo",        "Maese Gutiérrez",
                                                            "Tito Ramires",   "Nina la audaz",
                                                            "El foragido",    "Candelario",
                                                            "Rubén el Viejo", "Salomé",
                                                            "Don Atún",       "Capitán Fierro",
                                                            "Manolo Bidón",   "Paco el Tranquilo",
                                                            "Zulema",         "Yolanda",
                                                            "Valerio",        "Iván de los Precios",
                                                            "Florinda",       "Greta"};

VisitorFactory::VisitorFactory(RandomEventGenerator& rng, EngineData::GameConfig& config)
    : m_randomGenetor(&rng)
    , m_config(&config)
{
}

NPC::VisitanteVariant VisitorFactory::create(EngineData::Faction faction)
{
    static const std::unordered_map<EngineData::Faction, std::function<NPC::VisitanteVariant(::VisitorFactory*)>>
        FACTORY_MAP = {
            // {EngineData::Faction::RAIDERS,
            //  [](VisitorFactory* self)
            //  {
            //      auto name = self->m_randomGenetor->randomChoice(GROUPS_ENEMIES);
            //      auto cantidad =
            //          self->m_randomGenetor->getInt(self->m_config->fight.minEnemy, self->m_config->fight.minEnemy);
            //      auto poderFuego = self->m_randomGenetor->getDouble(0.0,
            //      self->m_config->fight.enemyAttackMultiplier);
            //      return Raider(
            //          name, cantidad, self->m_randomGenetor, poderFuego, self->m_config->fight.surrenderChance);
            //  }},
            // {EngineData::Faction::REFUGEES,
            //  [](VisitorFactory* self)
            //  {
            //      auto name = self->m_randomGenetor->randomChoice(NAMES);
            //      auto surname = self->m_randomGenetor->randomChoice(SURNAMES);
            //      auto fullName = name + " " + surname;
            //      bool isFromVault = self->m_randomGenetor->chance(0.5);
            //      auto bag = self->bagGenerator(isFromVault);
            //      return Refugee(fullName, isFromVault, bag);
            //  }},
            {EngineData::Faction::CARAVAN,
             [](VisitorFactory* self)
             {
                 auto name = self->m_randomGenetor->randomChoice(MERCHANTS);
                 bool confia = self->m_randomGenetor->chance(0.5);
                 return Caravan(name, confia, self->m_randomGenetor);
             }}};

    auto itMap = FACTORY_MAP.find(faction);
    if (itMap != FACTORY_MAP.end())
    {
        return itMap->second(this);
    }

    throw std::runtime_error("Facción no válida");
}

std::unordered_map<EngineData::Resources, uint8_t> VisitorFactory::bagGenerator(bool isFromVault)
{
    {
        std::unordered_map<EngineData::Resources, uint8_t> bag = {
            {EngineData::Resources::FOOD, static_cast<uint8_t>(m_randomGenetor->getInt(1, 5))},
            {EngineData::Resources::WATER, static_cast<uint8_t>(m_randomGenetor->getInt(1, 5))},
            {EngineData::Resources::MEDICINE, static_cast<uint8_t>(m_randomGenetor->getInt(0, 2))},
            {EngineData::Resources::AMMO, static_cast<uint8_t>(m_randomGenetor->getInt(0, 3))},
            {EngineData::Resources::TOOLS, static_cast<uint8_t>(m_randomGenetor->getInt(0, 2))}};

        if (isFromVault)
        {
            bag[EngineData::Resources::ELECTRONICS] = static_cast<uint8_t>(m_randomGenetor->getInt(0, 1));
            bag[EngineData::Resources::MATERIALS] = static_cast<uint8_t>(m_randomGenetor->getInt(0, 2));
            bag[EngineData::Resources::ALCHOHOL] = static_cast<uint8_t>(m_randomGenetor->getInt(0, 1));
        }

        return bag;
    }
}
