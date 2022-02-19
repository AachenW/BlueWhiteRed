#include <functional>

std::function<void(Node*,const BlendFunc&)> blendFucCall;

blendFucCall = [&blendFucCall](Node *container,const BlendFunc &blendFunc)
{
    for ( auto child : container->getChildren())
    {
        auto sp = dynamic_cast<Sprite*>(child);
        if (sp)
        {
            sp->setBlendFunc(blendFunc);
        }
        else
        {
            blendFucCall(child,blendFunc);
        }
    }
};
blendFucCall(this,blendFunc);