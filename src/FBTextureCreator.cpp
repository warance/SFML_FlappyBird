#pragma once

#include "SFML/Graphics.hpp"
#include <unordered_map>
#include <memory>
#include "FBTextureCreator.h"

TextureCreator::TextureCreator() {};

std::shared_ptr<sf::Texture> TextureCreator::CreateTexture(std::string path, bool repeatTexture)
{
    auto itr = m_mapTexture.find(path);

    //if the texture already exist
    if(itr != m_mapTexture.end())
    {
        return itr->second;
    }
    else
    {
        sf::Texture texture;
        texture.loadFromFile(path);
        texture.setRepeated(repeatTexture);
        auto id = path + std::to_string(repeatTexture);
        m_mapTexture[id] = std::make_shared<sf::Texture>(texture);
        return m_mapTexture[id];
    }
}

