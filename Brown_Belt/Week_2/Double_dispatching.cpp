#include "geo2d.h"
#include "game_object.h"

#include "test_runner.h"

#include <vector>
#include <memory>

using namespace std;

template <typename T>
struct Collider : GameObject {
  bool Collide(const GameObject& that) const override {
    return that.CollideWith(static_cast<const T&>(*this));
  }
};

class Unit : public Collider<Unit> {
public:
  Unit(geo2d::Point position) : position_(position) {
  }

  geo2d::Point GetPosition() const { return position_; }

  bool CollideWith(const Unit& that) const override;
  bool CollideWith(const Building& that) const override;
  bool CollideWith(const Tower& that) const override;
  bool CollideWith(const Fence& that) const override;

private:
  geo2d::Point position_;
};

class Building : public Collider<Building> {
public:
  Building(geo2d::Rectangle geometry)
    : geometry_(geometry)
  {
  }