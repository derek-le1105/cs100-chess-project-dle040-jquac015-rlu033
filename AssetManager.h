#ifndef SFML_PROJECT_ASSETMANAGER_H
#define SFML_PROJECT_ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
class AssetManager {
public:
    AssetManager(){}
    ~AssetManager(){}

    void loadTexture(std::string name, std::string fileName);
    sf::Texture &getTexture(std::string name);
    void loadFont(std::string name, std::string fileName);
    sf::Font &getFont(std::string name);

private:
    std::map<std::string, sf::Texture>  _textures;
    std::map<std::string, sf::Font>  _fonts;
};


#endif //SFML_PROJECT_ASSETMANAGER_H
