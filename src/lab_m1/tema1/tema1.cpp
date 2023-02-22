#include "lab_m1/tema1/tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"

using namespace std;
using namespace m1;


tema1::tema1()
{
}


tema1::~tema1()
{
}


void tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    duck_size = 160;
    speed = 720;

    translateX = 640;
    translateY = 100;
    
    scaleX = 1;
    scaleY = 1;

    angularStep = 0;


    Mesh* bullet1 = object2D::CreateSquare("bullet1", glm::vec3(1152, 682, 0), 27, glm::vec3(0.8, 0.4, 0), true);
    AddMeshToList(bullet1);

    Mesh* bullet2 = object2D::CreateSquare("bullet2", glm::vec3(1192, 682, 0), 27, glm::vec3(0.8, 0.4, 0), true);
    AddMeshToList(bullet2);

    Mesh* bullet3 = object2D::CreateSquare("bullet3", glm::vec3(1232, 682, 0), 27, glm::vec3(0.8, 0.4, 0), true);
    AddMeshToList(bullet3);

    Mesh* heart1 = object2D::CreateHeart("heart1", glm::vec3(980, 670, 0), 50);
    AddMeshToList(heart1);

    Mesh* heart2 = object2D::CreateHeart("heart2", glm::vec3(1030, 670, 0), 50);
    AddMeshToList(heart2);

    Mesh* heart3 = object2D::CreateHeart("heart3", glm::vec3(1080, 670, 0), 50);
    AddMeshToList(heart3);

    Mesh* score1 = object2D::CreateScore("score1", glm::vec3(980, 620, 0), glm::vec3(0, 0, 0.7));
    AddMeshToList(score1);

    Mesh* score2 = object2D::CreateScore("score2", glm::vec3(980 + 29, 620, 0), glm::vec3(0, 0, 0.7));
    AddMeshToList(score2);

    Mesh* score3 = object2D::CreateScore("score3", glm::vec3(980 + 2*29, 620, 0), glm::vec3(0, 0, 0.7));
    AddMeshToList(score3);

    Mesh* score4 = object2D::CreateScore("score4", glm::vec3(980 + 3 * 29, 620, 0), glm::vec3(0, 0, 0.7));
    AddMeshToList(score4);

    Mesh* score5 = object2D::CreateScore("score5", glm::vec3(980 + 4 * 29, 620, 0), glm::vec3(0, 0, 0.7));
    AddMeshToList(score5);

    Mesh* score6 = object2D::CreateScore("score6", glm::vec3(980 + 5 * 29, 620, 0), glm::vec3(0, 0, 0.7));
    AddMeshToList(score6);

    Mesh* score7 = object2D::CreateScore("score7", glm::vec3(980 + 6 * 29, 620, 0), glm::vec3(0, 0, 0.7));
    AddMeshToList(score7);

    Mesh* score8 = object2D::CreateScore("score8", glm::vec3(980 + 7 * 29, 620, 0), glm::vec3(0, 0, 0.7));
    AddMeshToList(score8);

    Mesh* score9 = object2D::CreateScore("score9", glm::vec3(980 + 8 * 29, 620, 0), glm::vec3(0, 0, 0.7));
    AddMeshToList(score9);

    Mesh* score10 = object2D::CreateScore("score10", glm::vec3(980 + 9 * 29, 620, 0), glm::vec3(0, 0, 0.7));
    AddMeshToList(score10);

    Mesh* wireFrame = object2D::CreateWireframe("wireFrame", glm::vec3(980, 620, 0), 300, glm::vec3(0, 0, 0));
    AddMeshToList(wireFrame);

    Mesh* hit_box = object2D::CreateSquare("hit_box", glm::vec3(-(duck_size / 2), -(duck_size / 2), 0), duck_size, glm::vec3(0, 0.75, 0), true);
    AddMeshToList(hit_box);

    Mesh* duck = object2D::CreateDuck("duck", glm::vec3(-(duck_size/2), -(duck_size/2), 0), duck_size, glm::vec3(0.5, 0.25, 0), true);
    AddMeshToList(duck);

    Mesh* wing_up = object2D::CreateWing("wing_up", glm::vec3(-(duck_size/2), -(duck_size/2), 0), duck_size, glm::vec3(0.5, 0.25, 0), true, true);
    AddMeshToList(wing_up);

    Mesh* wing_down = object2D::CreateWing("wing_down", glm::vec3(-(duck_size/2), -(duck_size/2), 0), duck_size, glm::vec3(0.5, 0.25, 0), true, false);
    AddMeshToList(wing_down);
    
    Mesh* grass = object2D::CreateGrass("grass", glm::vec3(0, 120, 0), 150, glm::vec3(0, 0.8, 0));
    AddMeshToList(grass);

}


void tema1::FrameStart()
{
    if (game_over) {
        glClearColor(0.35, 0, 0, 1);
    }
    else if (score >= 10) {
        glClearColor(0, 0.9, 0, 1);
    }
    else {
        glClearColor(0.2, 0.9, 1, 1);
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);
}


void tema1::Update(float deltaTimeSeconds)
{

    time_up += deltaTimeSeconds;

    if (game_over || score == 10) {
        exit_time += deltaTimeSeconds;
        if (exit_time > 3) {
            exit(0);
        }
    }

    if (bullets_count == 0) {
        refil_time += deltaTimeSeconds;
    }
    if (refil_time > 2) {
        bullets_count = 3;
        refil_time = 0;
    }


    if (duck_escaped) {

        duck_count++;
        if (duck_count > 4) {
            speed *= 1.3;
        }
        direction_x = (rand() % speed) - speed/2;
        direction_y = speed/2 - abs(direction_x);
        if (direction_y < 40) {
            direction_y += 40;
        }
        direction_duck = atan(direction_y / abs(direction_x));

        
        if (direction_x < 0) {
            direction_duck += 2*(M_PI / 2 - direction_duck);
        }
        bullets_count = 3;
        duck_escaped = false;
    }

    if (angularStep > 0.25) {
        flag = 1;
    } else if (angularStep < -0.25) {
        flag = 0;
    }

    if (time_up < 5 && duck_dead == false && bullets_count != 0) {
        
        translateX += deltaTimeSeconds * direction_x;
        translateY += deltaTimeSeconds * direction_y;

        if (flag == 0) {
            angularStep += 0.01;
        } else {
            angularStep -= 0.01;
        }
    }
    else if (duck_dead) {
        translateY -= deltaTimeSeconds * 400;
        direction_duck = M_PI * 3 / 2;
    }
    else {
        translateY += deltaTimeSeconds * 400;
        direction_duck = M_PI / 2;
    }

    // reflexie dreapta
    if (translateX > (1280 - duck_size/2.2)) {
        direction_duck = M_PI - direction_duck;
        direction_x = -direction_x;
    }
    // reflexie stanga
    if (translateX < duck_size / 2.2) {
        direction_duck = M_PI - direction_duck;
        direction_x = -direction_x;
    }
    // reflexie sus
    if (translateY > (720 - duck_size/2.2) && (time_up < 5) && bullets_count > 0) {
        direction_duck = 2*M_PI - direction_duck;
        direction_y = -direction_y;
    }
    // reflexie jos
    if (translateY < duck_size / 1.5 && !duck_dead) {
        direction_duck = 2*M_PI - direction_duck;
        direction_y = -direction_y;
    }
        
    // verific daca rata a iesit din cadru
    if (translateY > 720 + duck_size / 2.5 || translateY < -duck_size) {
        duck_escaped = true;
        translateX = 640;
        translateY = 120;
        direction_duck = M_PI / 2;
        translateX = rand() % 900 + 180;
        time_up = 0;

        if (!duck_dead) {
            lives--;
        }

        if (lives == 0) {
            game_over = true;
        }

        duck_dead = false;
    }
        

    // spawn the duck
    modelMatrix = glm::mat3(1);

    if (!game_over && score < 10) {

        RenderMesh2D(meshes["wireFrame"], shaders["VertexColor"], modelMatrix);

        if (score > 0) {
            RenderMesh2D(meshes["score1"], shaders["VertexColor"], modelMatrix);
        }
        if (score > 1) {
            RenderMesh2D(meshes["score2"], shaders["VertexColor"], modelMatrix);
        }
        if (score > 2) {
            RenderMesh2D(meshes["score3"], shaders["VertexColor"], modelMatrix);
        }
        if (score > 3) {
            RenderMesh2D(meshes["score4"], shaders["VertexColor"], modelMatrix);
        }
        if (score > 4) {
            RenderMesh2D(meshes["score5"], shaders["VertexColor"], modelMatrix);
        }
        if (score > 5) {
            RenderMesh2D(meshes["score6"], shaders["VertexColor"], modelMatrix);
        }
        if (score > 6) {
            RenderMesh2D(meshes["score7"], shaders["VertexColor"], modelMatrix);
        }
        if (score > 7) {
            RenderMesh2D(meshes["score8"], shaders["VertexColor"], modelMatrix);
        }
        if (score > 8) {
            RenderMesh2D(meshes["score9"], shaders["VertexColor"], modelMatrix);
        }
        if (score > 9) {
            RenderMesh2D(meshes["score10"], shaders["VertexColor"], modelMatrix);
        }

        if (lives > 0) {
            RenderMesh2D(meshes["heart1"], shaders["VertexColor"], modelMatrix);
        }
        if (lives > 1) {
            RenderMesh2D(meshes["heart2"], shaders["VertexColor"], modelMatrix);
        }
        if (lives > 2) {
            RenderMesh2D(meshes["heart3"], shaders["VertexColor"], modelMatrix);
        }

        if (bullets_count > 0) {
            RenderMesh2D(meshes["bullet1"], shaders["VertexColor"], modelMatrix);
        }
        if (bullets_count > 1) {
            RenderMesh2D(meshes["bullet2"], shaders["VertexColor"], modelMatrix);
        }
        if (bullets_count > 2) {
            RenderMesh2D(meshes["bullet3"], shaders["VertexColor"], modelMatrix);
        }

        RenderMesh2D(meshes["grass"], shaders["VertexColor"], modelMatrix);

        modelMatrix *= transform2D::Translate(translateX, translateY);
        modelMatrix *= transform2D::Rotate(direction_duck);

        RenderMesh2D(meshes["duck"], shaders["VertexColor"], modelMatrix);
        //RenderMesh2D(meshes["hit_box"], shaders["VertexColor"], modelMatrix);

        modelMatrix *= transform2D::Rotate(angularStep);
        RenderMesh2D(meshes["wing_up"], shaders["VertexColor"], modelMatrix);

        modelMatrix *= transform2D::Rotate((-2) * angularStep);
        RenderMesh2D(meshes["wing_down"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);

    }



}


void tema1::FrameEnd()
{
}



void tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void tema1::OnKeyPress(int key, int mods)
{
}


void tema1::OnKeyRelease(int key, int mods)
{
}


void tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
}


void tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    glm::ivec2 resolution = window->GetResolution();
    float mouseX_new = (float)mouseX * 1280 / resolution.x;
    float mouseY_new = (float)mouseY * 720 / resolution.y;

    cout << "mouseX_new = " << mouseX_new << "mouseX = " << mouseX <<  endl;
    cout << "mouseY_new = " << mouseY_new << "mouseY = " << mouseY << endl;


    if (bullets_count > 0) {

        if (mouseX_new >= (translateX - duck_size / 2) && mouseX_new <= (translateX + duck_size / 2)) {
            if (720 - mouseY_new >= (translateY  - duck_size / 2) && 720 - mouseY_new <= (translateY + duck_size / 2)) {
                score++;
                duck_dead = true;
            }
        }
        bullets_count--;
    }
}


void tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}


void tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void tema1::OnWindowResize(int width, int height)
{
}
