#ifndef MAPNODE_HXX_
#define MAPNODE_HXX_

#include <SDL.h>

#include <memory>
#include <string>
#include <algorithm>

#include "../sprite.hxx"
#include "../common/Enums.hxx"
#include "../basics/point.hxx"

#include "../tileManager.hxx"

/** @brief Class that holds map nodes
 * Each tile is represented by the map nodes class.
 */

class MapNode
{
public:
  MapNode(Point isoCoordinates, const std::string &terrainID, const std::string &tileID = "");
  ~MapNode() = default;

  /** @brief get Sprite
    * get the Sprite* object for this nodes
    * @see Sprite
    */
  Sprite *getSprite() const { return m_sprite.get(); };

  /// get iso coordinates of this node
  const Point &getCoordinates() const { return m_isoCoordinates; };

  void setCoordinates(const Point &newIsoCoordinates);

  /** @brief Increase Height
    * Increases the height of the node and its sprite
    * This function should not be called directly, but only from where the neighboring nodes slopes are determined
    */
  void increaseHeight();

  /** @brief Decrease Height 
    * Decreases the height of the node and its sprite
    * This function should not be called directly, but only from where the neighboring nodes slopes are determined
    */
  void decreaseHeight();

  /** @brief Render MapNode
  * Renders the sprite object(s) of the node
  */
  void render() const;

  void setBitmask(unsigned char elevationBitmask, unsigned char tileTypeBitmask);

  //bool isLayerActive(Layer layer) const { return std::find(layers.begin(), layers.end(), layer) != layers.end(); };

  unsigned char getElevationBitmask() const { return m_elevationBitmask; };

  const TileData *getTileData() const { return m_tileData; };

  const std::string &getTileID() const
  {
    if (m_tileID.empty())
      return m_tileIDTerrain;
    else
      return m_tileID;
  };
  void setTileID(const std::string &tileType);
  size_t tileMap = TileMap::DEFAULT;

private:
  Point m_isoCoordinates;
  std::unique_ptr<Sprite> m_sprite;

  int m_maxHeight = 32;

  std::string m_tileIDTerrain = "terrain";
  std::string m_tileID;
  std::string m_previousTileID = "terrain";

  size_t m_orientation = TileSlopes::DEFAULT_ORIENTATION;

  int m_clippingWidth = 0;

  TileData *m_tileData = nullptr;

  unsigned char m_elevationBitmask = 0;
  unsigned char m_tileIDBitmask = 0;

  void updateTexture();
};

#endif
