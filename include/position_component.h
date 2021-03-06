#ifndef ACID_INCLUDE_POSITION_COMPONENT_H_
#define ACID_INCLUDE_POSITION_COMPONENT_H_


#include <i_component.h>
#include <SFML/System.hpp>


class PositionComponent: public IComponent {
  public:
    sf::Vector2f& get_coords() {
        return coordinate;
    }

    void set_coords(sf::Vector2f& coords) {
        coordinate = coords;
        update();
    }

  private:
    sf::Vector2f coordinate;
};

#endif  // ACID_INCLUDE_POSITION_COMPONENT_H_
