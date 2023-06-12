#include "Paddle.h"

Paddle::Paddle()
{
    boxCollider = BoxCollider();
}


void Paddle::OnStart()
{
	boxCollider.localTransform = this->globalTransform;
    BoxCollider* boxColliderptr = &boxCollider;
    boxCollider.InitBox
    (
        this->globalTransform.m20,
        this->globalTransform.m21,
        3,
        40,
        BLACK
    );

    this->AddChild(boxColliderptr);


}
