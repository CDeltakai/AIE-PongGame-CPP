#include "SceneObject.h"
#include <iostream>
#include <list>

SceneObject::SceneObject()
{
	localTransform = Matrix3(1);
	globalTransform = Matrix3(1);
	parent = nullptr;
    children = std::list<SceneObject*>();


}

SceneObject::~SceneObject()
{
    //if (parent != nullptr)
    //{
    //    parent->RemoveChild(*this);
    //}

    for (SceneObject* so : children)
    {
        so->parent = nullptr;
    }

}

void SceneObject::OnStart()
{
}

void SceneObject::OnUpdate(float deltaTime)
{
}

void SceneObject::OnDraw()
{
}

void SceneObject::Update(float deltaTime)
{
    OnUpdate(deltaTime);
    for (SceneObject* child : children)
    {
        child->Update(deltaTime);
    }
}

void SceneObject::Draw()
{
    OnDraw();
    for (SceneObject* child : children)
    {
        child->Draw();
    }
}

void SceneObject::UpdateTransform()
{
    if (parent != nullptr)
        globalTransform = parent->globalTransform * localTransform;
    else
        globalTransform = localTransform;

    for (SceneObject* child : children)
    {
        child->UpdateTransform();
    }
}

void SceneObject::AddChild(SceneObject* child)
{

    child->parent = this;

    children.push_back(child);

}

void SceneObject::RemoveChild(SceneObject child)
{
    //children.remove(child);

}

void SceneObject::SetPosition(float x, float y)
{
    localTransform.SetTranslation(x, y);
    UpdateTransform();
}

void SceneObject::Translate(float x, float y)
{
    localTransform.Translate(x, y);
    UpdateTransform();

}
