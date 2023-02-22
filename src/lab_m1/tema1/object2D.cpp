#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"

Mesh* object2D::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3, 0, 2};


    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateGrass(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float heigth,
    glm::vec3 color)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices;

    vertices.push_back(VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0.3, 0.2, 0)));
    vertices.push_back(VertexFormat(glm::vec3(1280, 0 ,0), glm::vec3(0.3, 0.2, 0)));
    vertices.push_back(VertexFormat(glm::vec3(1280, 120, 0), glm::vec3(0.3, 0.2, 0)));
    vertices.push_back(VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0.3, 0.2, 0)));
    vertices.push_back(VertexFormat(glm::vec3(1280, 120, 0), glm::vec3(0.3, 0.2, 0)));
    vertices.push_back(VertexFormat(glm::vec3(0, 120, 0), glm::vec3(0.3, 0.2, 0)));


    for(int i = 0; i < 1320; i += 15)
    {
        vertices.push_back(VertexFormat(corner + glm::vec3(i, 0, 0), color));
        vertices.push_back(VertexFormat(corner + glm::vec3(i + 8, 0, 0), color));
        vertices.push_back(VertexFormat(corner + glm::vec3(i + 45, heigth, 0), color));

        vertices.push_back(VertexFormat(corner + glm::vec3(i, 0, 0), color));
        vertices.push_back(VertexFormat(corner + glm::vec3(i + 13, 0, 0), color));
        vertices.push_back(VertexFormat(corner + glm::vec3(i - 45, heigth, 0), color));
    }

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices;

    for (int i = 0; i < vertices.size(); i++) {
        indices.push_back(i);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateScore(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    glm::vec3 color)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(3, 5, 0), color),
        VertexFormat(corner + glm::vec3(29, 5, 0), color),
        VertexFormat(corner + glm::vec3(29, 45, 0), color),
        VertexFormat(corner + glm::vec3(3, 5, 0), color),
        VertexFormat(corner + glm::vec3(29, 45, 0), color),
        VertexFormat(corner + glm::vec3(3, 45, 0), color),

    };

    Mesh* score = new Mesh(name);
    std::vector<unsigned int> indices;

    for (int i = 0; i < vertices.size(); i++) {
        indices.push_back(i);
    }

    score->InitFromData(vertices, indices);
    return score;
}


Mesh* object2D::CreateWireframe(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length, glm::vec3 color)
{
    glm::vec3 corner = leftBottomCorner;
    float heigth = length / 3;

    std::vector<VertexFormat> vertices =
    {
        // first frame
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length * 0.97, 0, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, 5, 0), color),
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length * 0.97, 5, 0), color),
        VertexFormat(corner + glm::vec3(0, 5, 0), color),

        VertexFormat(corner + glm::vec3(length * 0.97 - 5, 0, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, 0, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, heigth * 0.45, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97 - 5, 0, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, heigth * 0.45, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97 - 5, heigth * 0.45, 0), color),

        VertexFormat(corner + glm::vec3(0, heigth * 0.45, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, heigth * 0.45, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, heigth * 0.45 + 5, 0), color),
        VertexFormat(corner + glm::vec3(0, heigth * 0.45, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, heigth * 0.45 + 5, 0), color),
        VertexFormat(corner + glm::vec3(0, heigth * 0.45 + 5, 0), color),

        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(5, 0, 0), color),
        VertexFormat(corner + glm::vec3(5, heigth * 0.45, 0), color),
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(5, heigth * 0.45, 0), color),
        VertexFormat(corner + glm::vec3(0, heigth * 0.45, 0), color),

        // second frame

        VertexFormat(corner + glm::vec3(length * 0.55 - 5, heigth * 0.55, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, heigth * 0.55, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, heigth * 0.55 + 5, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.55 - 5, heigth * 0.55, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, heigth * 0.55 + 5, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.55 - 5, heigth * 0.55 + 5, 0), color),

        VertexFormat(corner + glm::vec3(length * 0.97 - 5, heigth * 0.55, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, heigth * 0.55, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, heigth * 0.90, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97 - 5, heigth * 0.55, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, heigth * 0.90, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97 - 5, heigth * 0.90, 0), color),

        VertexFormat(corner + glm::vec3(length * 0.55 - 5, heigth * 0.90, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, heigth * 0.90, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, heigth * 0.90 + 5, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.55 - 5, heigth * 0.90, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.97, heigth * 0.90 + 5, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.55 - 5, heigth * 0.90 + 5, 0), color),

        VertexFormat(corner + glm::vec3(length * 0.55 - 5, heigth * 0.55, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.55, heigth * 0.55, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.55, heigth * 0.90, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.55 - 5, heigth * 0.55, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.55, heigth * 0.90, 0), color),
        VertexFormat(corner + glm::vec3(length * 0.55 - 5, heigth * 0.90, 0), color),

    };

    Mesh* WireFrame = new Mesh(name);
    std::vector<unsigned int> indices;

    for (int i = 0; i < vertices.size(); i++) {
        indices.push_back(i);
    }

    

    WireFrame->InitFromData(vertices, indices);
    return WireFrame;
}

Mesh* object2D::CreateHeart(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length)
{
    glm::vec3 corner = leftBottomCorner;
    float heigth = length;
    float circle_origin_x_1 = length * 0.3;
    float circle_origin_x_2 = length * 0.7;
    float circle_origin_y = heigth * 0.66;
    float circle_x, circle_y;
    float circle_raza = length / 4;
    int resolution = 36;
    float step = 360 / resolution;
   

    std::vector<VertexFormat> circle;

    // doua cercuri lipite
    for (int i = 0; i < resolution; i++) {

        circle.push_back(VertexFormat(corner + glm::vec3(circle_origin_x_1, circle_origin_y, 0), glm::vec3(0.8, 0, 0)));

        circle_x = circle_origin_x_1 + cos(i * RADIANS(step)) * circle_raza;
        circle_y = circle_origin_y + sin(i * RADIANS(step)) * circle_raza;

        circle.push_back(VertexFormat(corner + glm::vec3(circle_x, circle_y, 0), glm::vec3(0.8, 0, 0)));


        circle_x = circle_origin_x_1 + cos((i + 1) * RADIANS(step)) * circle_raza;
        circle_y = circle_origin_y + sin((i + 1) * RADIANS(step)) * circle_raza;

        circle.push_back(VertexFormat(corner + glm::vec3(circle_x, circle_y, 0), glm::vec3(0.8, 0, 0)));
    }


    for (int i = 0; i < resolution; i++) {

        circle.push_back(VertexFormat(corner + glm::vec3(circle_origin_x_2, circle_origin_y, 0), glm::vec3(0.8, 0, 0)));

        circle_x = circle_origin_x_2 + cos(i * RADIANS(step)) * circle_raza;
        circle_y = circle_origin_y + sin(i * RADIANS(step)) * circle_raza;

        circle.push_back(VertexFormat(corner + glm::vec3(circle_x, circle_y, 0), glm::vec3(0.8, 0, 0)));


        circle_x = circle_origin_x_2 + cos((i + 1) * RADIANS(step)) * circle_raza;
        circle_y = circle_origin_y + sin((i + 1) * RADIANS(step)) * circle_raza;

        circle.push_back(VertexFormat(corner + glm::vec3(circle_x, circle_y, 0), glm::vec3(0.8, 0, 0)));
    }


    std::vector<VertexFormat> vertices =
    {
        // triunghi inima
        VertexFormat(corner + glm::vec3(circle_origin_x_1 - circle_raza, heigth * 0.57, 0), glm::vec3(0.8, 0, 0)),
        VertexFormat(corner + glm::vec3(circle_origin_x_2 + circle_raza, heigth * 0.57, 0), glm::vec3(0.8, 0, 0)),
        VertexFormat(corner + glm::vec3((circle_origin_x_2 + circle_raza)*0.528, 0, 0), glm::vec3(0.8, 0, 0))
    };

    Mesh* heart = new Mesh(name);
    std::vector<unsigned int> indices;

    std::vector<VertexFormat> final(circle);
    final.insert(final.end(), vertices.begin(), vertices.end());

    for (int i = 0; i < final.size(); i++) {
        indices.push_back(i);
    }
    

    heart->InitFromData(final, indices);
    return heart;
}


Mesh* object2D::CreateWing(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill, bool up)
{
    glm::vec3 corner = leftBottomCorner;

    float heigth = length;
    float wing1 = length * 0.4;
    float wing2 = length * 0.66;
    float wing_pick = length * 0.5;
    float sus = 0;

    if (up) {
        sus = heigth;
    }

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(wing1, heigth / 2, 0), color),
        VertexFormat(corner + glm::vec3(wing2, heigth / 2, 0), color),
        VertexFormat(corner + glm::vec3(wing_pick, sus, 0), color),
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };


    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateDuck(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;
    float heigth = length;
    float _1 = heigth / 2 - heigth / 5;
    float _2 = length - length / 5;
    float _3 = heigth / 2;
    float _4 = heigth / 2 + heigth / 5;
    float wing1 = length * 0.4;
    float wing2 = length * 0.66;
    float wing_pick = length * 0.5;
    float cioc_x = length - length / 7;
    float cioc_y = heigth / 1.9;
    float circle_origin_x = _2;
    float circle_origin_y = _3;
    float circle_x, circle_y;
    float circle_raza = length / 8;
    int resolution = 36;
    float step = 360 / resolution;

    std::vector<VertexFormat> circle;

    for (int i = 0; i < resolution; i++) {

        circle.push_back(VertexFormat(corner + glm::vec3(circle_origin_x, circle_origin_y, 0), glm::vec3(0, 0.4, 0)));

        circle_x = circle_origin_x + cos(i * RADIANS(step)) * circle_raza;
        circle_y = circle_origin_y + sin(i * RADIANS(step)) * circle_raza;

        circle.push_back(VertexFormat(corner + glm::vec3(circle_x, circle_y, 0), glm::vec3(0, 0.4, 0)));

        
        circle_x = circle_origin_x + cos((i+1) * RADIANS(step)) * circle_raza;
        circle_y = circle_origin_y + sin((i+1) * RADIANS(step)) * circle_raza;

        circle.push_back(VertexFormat(corner + glm::vec3(circle_x, circle_y, 0), glm::vec3(0, 0.4, 0)));
    }




    std::vector<VertexFormat> corp =
    {
        // corp
        VertexFormat(corner + glm::vec3(0, _1, 0), color),
        VertexFormat(corner + glm::vec3(_2, _3, 0), color),
        VertexFormat(corner + glm::vec3(0, _4, 0), color),
        // cioc
        VertexFormat(corner + glm::vec3(cioc_x, cioc_y - heigth / 10, 0), glm::vec3(1, 1, 0)),
        VertexFormat(corner + glm::vec3(cioc_x, cioc_y, 0), glm::vec3(1, 1, 0)),
        VertexFormat(corner + glm::vec3(length, heigth * 0.45, 0), glm::vec3(1, 1, 0))

    };

    std::vector<VertexFormat> final(circle);
    final.insert(final.end(), corp.begin(), corp.end());

    Mesh* duck = new Mesh(name);
    std::vector<unsigned int> indices;

    for (int i = 0; i < final.size(); i++) {
        indices.push_back(i);
    }

    duck->InitFromData(final, indices);
    return duck;
}
