#pragma once
#include "SceneObject.h"
#include "Matrix3.h"
#include <list>

class SceneObject
{
public:
	SceneObject* parent = nullptr;
	std::list<SceneObject*> children;

public:
	SceneObject();
	~SceneObject();
	Matrix3 localTransform;
	Matrix3 globalTransform;
	
	virtual void OnStart();
	virtual void OnUpdate(float deltaTime);
	virtual void OnDraw();
	void Update(float deltaTime);
	void Draw();
	void UpdateTransform();
	void AddChild(SceneObject* child);
	void RemoveChild(SceneObject child);

	void SetPosition(float x, float y);
	void Translate(float x, float y);

	
};

