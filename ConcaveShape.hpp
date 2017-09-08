#ifndef CONCAVESHAPE_HPP
#define CONCAVESHAPE_HPP
//---------------------------------------------------------------------------//
#include <vector>
//-----------------------------------//
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
//-----------------------------------//
namespace zabarovka {
namespace sfml {

class ConcaveShape: public sf::Drawable, public sf::Transformable {
  private:
    std::vector<sf::VertexArray> triangles;
    std::vector<sf::Vector2f> points;
    const sf::Texture* texture;
    sf::Color color;
    float Area() const;
    bool PointOnLine(sf::Vector2f pt,sf::Vector2f v1,sf::Vector2f v2) const;
    bool PointInTriangle(sf::Vector2f p,sf::Vector2f p1,sf::Vector2f p2,sf::Vector2f p3) const;
    void CreateTriangle(unsigned int a,unsigned int b,unsigned int c);
    void TriangulateInner(unsigned int n,std::vector<unsigned int>& p);
  public:
    explicit ConcaveShape(sf::Color c=sf::Color::Black);
    explicit ConcaveShape(const sf::Texture& t,sf::Color c=sf::Color::Black);
    ~ConcaveShape();
    void addPoint(sf::Vector2f point);
    void Triangulate();
    void setColor(sf::Color c);
    void setTexture(const sf::Texture& t);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
      states.texture=texture;
      for (auto& i:triangles) {target.draw(i,states);}
    }
};

}
}
//---------------------------------------------------------------------------//
#endif // CONCAVESHAPE_HPP
