#ifndef ACID_INCLUDE_MOVE_SYSTEM_H_
#define ACID_INCLUDE_MOVE_SYSTEM_H_


#include <reactive_system.h>
#include <move_node.h>


class MoveSystem: public ReactiveSystem<MoveNode> {
  public:
    void execute() const override {
        for (auto& node : reactive_nodes) {
            auto input_move_comp = node->get_component<InputMoveComponent>();
            auto pos_comp = node->get_component<PositionComponent>();

            auto keys = input_move_comp->get_keys();
            auto pos = pos_comp->get_coords();
            if (keys[sf::Keyboard::W]) {
                pos.y -= 1;
            }
            if (keys[sf::Keyboard::A]) {
                pos.x -= 1;
            }
            if (keys[sf::Keyboard::S]) {
                pos.y += 1;
            }
            if (keys[sf::Keyboard::D]) {
                pos.x += 1;
            }
            pos_comp->set_coords(pos);
        }
    }
};


#endif  // ACID_INCLUDE_MOVE_SYSTEM_H_
