#ifndef LOCATION_H
#define LOCATION_H

#include <string>       // Using std::string for text
#include <map>          // Using std::map for mapping directions to locations
#include <vector>       // Using std::vector for storing lists of NPCs and items
#include "npc.h"        // NPC class header (assuming it's provided)
#include "item.h"       // Item class header (assuming it's provided)

// Represents a location in a game, with details about name, description, neighboring locations, NPCs, and items
class Location {
public:
    // Constructor: initializes Location with a name and description
    Location(const std::string& name, const std::string& description);

    // Returns the name of the location
    std::string getName() const;

    // Returns the description of the location
    std::string getDescription() const;

    // Gets the neighboring locations as a map (direction -> Location)
    std::map<std::string, Location> getLocations() const;

    // Adds a neighboring location in a given direction (e.g., "north")
    void addLocation(const std::string& direction, const Location& location);

    // Adds an NPC to the location
    void addNPC(const npc& npc);

    // Gets all NPCs in the location
    std::vector<npc> getNPCs() const;

    // Adds an item to the location
    void addItem(const item& item);

    // Gets all items in the location
    std::vector<item> getItems() const;

    // Marks the location as visited
    void setVisited();

    // Checks if the location has been visited
    bool getVisited() const;

    // Overloads the << operator to print location details (name, description, NPCs, items, directions)
    friend std::ostream& operator<<(std::ostream& os, const Location& location);

private:
    std::string name;                           // Name of the location
    std::string description;                    // Description of the location
    bool visited;                               // True if the location has been visited
    std::map<std::string, Location> neighbors;  // Neighboring locations by direction
    std::vector<npc> npcs;                      // List of NPCs in the location
    std::vector<item> items;                    // List of items in the location
};

#endif
