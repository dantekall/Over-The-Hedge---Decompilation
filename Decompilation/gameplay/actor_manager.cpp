// gameplay/actor_manager.cpp
#include <string>
#include <vector>
#include <memory>

class EIActor {
public:
    virtual ~EIActor() = default;
    virtual void Initialize() = 0;
    virtual void Update(float deltaTime) = 0;
};

class RaccoonActor : public EIActor {
private:
    std::string name;
    float health;

public:
    RaccoonActor(const std::string& actorName) : name(actorName), health(100.0f) {}

    void Initialize() override {
        // Initialize RJ-specific controller inputs and animations
    }

    void Update(float deltaTime) override {
        // Handle movement, stealth mechanics, and item interaction
    }
};

class TurtleActor : public EIActor {
private:
    std::string name;
    float health;

public:
    TurtleActor(const std::string& actorName) : name(actorName), health(100.0f) {}

    void Initialize() override {
        // Initialize Verne-specific defense and shell mechanics
    }

    void Update(float deltaTime) override {
        // Handle push/pull physics interactions and navigation
    }
};

class ActorManager {
private:
    std::vector<std::unique_ptr<EIActor>> activeActors;

public:
    void SpawnDefaultCharacters() {
        // Spawn RJ (Player 1) and Verne (Player 2) based on string definitions
        activeActors.push_back(std::make_unique<RaccoonActor>("RJ"));
        activeActors.push_back(std::make_unique<TurtleActor>("Verne"));

        for (auto& actor : activeActors) {
            actor->Initialize();
        }
    }

    void UpdateAll(float deltaTime) {
        for (auto& actor : activeActors) {
            actor->Update(deltaTime);
        }
    }
};