#include "location.h"
#include <stdexcept>    // For throwing exceptions like std::invalid_argument
#include <iostream>     // For std::ostream output

// Constructor: initializes Location with name, description, and sets visited to false
Location::Location(const std::string& name, const std::string& description)
    : name(name), description(description), visited(false) {
}

// Gets the name of the location
std::string Location::getName() const {
    return name;
}

// Gets the description of the location
std::string Location::getDescription() const {
    return description;
}

// Returns all neighboring locations as a map
std::map<std::string, Location> Location::getLocations() const {
    return neighbors;
}

// Adds a neighboring location in a given direction; throws an error if the direction is empty or already used
void Location::addLocation(const std::string& direction, const Location& location) {
    if (direction.empty()) {
        throw std::invalid_argument("Direction cannot be empty.");
    }
    if (neighbors.find(direction) != neighbors.end()) {
        throw std::runtime_error("Direction already exists.");
    }
    neighbors[direction] = location;
}

// Adds an NPC to the location
void Location::addNPC(const npc& npc) {
    npcs.push_back(npc);
}

// Gets all NPCs present in the location
std::vector<npc> Location::getNPCs() const {
    return npcs;
}

// Adds an item to the location
void Location::addItem(const item& item) {
    items.push_back(item);
}

// Gets all items present in the location
std::vector<item> Location::getItems() const {
    return items;
}

// Marks the location as visited
void Location::setVisited() {
    visited = true;
}

// Checks if the location has been visited
bool Location::getVisited() const {
    return visited;
}

// Overloads the << operator to print location details (name, description, NPCs, items, directions)
std::ostream& operator<<(std::ostream& os, const Location& location) {
    os << location.name << " - " << location.description << "\n";

    os << "You see the following NPCs:\n";
    for (const auto& npc : location.npcs) {
        os << "    - " << npc << "\n";  // Assumes npc class has << operator defined
    }

    os << "You see the following Items:\n";
    for (const auto& item : location.items) {
        os << "    - " << item << "\n";  // Assumes item class has << operator defined
    }

    os << "You can go in the following Directions:\n";
    for (const auto& neighbor : location.neighbors) {
        os << "    - " << neighbor.first << " - "
           << neighbor.second.getName() << (neighbor.second.getVisited() ? " (Visited)" : "") << "\n";
    }

    return os;
}
