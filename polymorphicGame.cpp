//基本思路
//为每个怪物类编写 Attack FightBack 和 Hurt成员函数
//Attack函数表现攻击动作，攻击某个怪物，并调用被攻击怪物的Hurt函数来减少被攻击怪物的生命值，
//同时也调用攻击怪物的FightBack函数遭到被攻击怪物的反击
//Hurt函数减少自身生命之并且做出受伤的动作
//FightBack成员函数表现反击动作，并调用被反击对象的Hurt函数是被反击对象受伤
/*
    * 设计思路
    * 设置基类CCreature，并使CDragon，CWolf等怪物从其派生而来
    *
*/

//#define NON_POLYMORPHIC
#ifdef NON_POLYMORPHIC//非多态的实现方式
class CCreature
{
private:

public:
    CCreature()
    {}
    ~CCreature()
    {}
protected:
    int nPower;//攻击力
    int nLifeValue;//血量
};
class CWolf: public CCreature
{
public:
    void Hurt(int damage)
    {
        nLifeValue -= damage;
    }
    void FightBack(CCreature *target)
    {
    }
};
class CGhost: public CCreature
{
public:
    void Hurt(int n)
    {
        nLifeValue -= n;
    }
    void FightBack(CCreature *target)
    {
    }
};
class CAngle: public CCreature
{
public:
    void Hurt(int n)
    {
        nLifeValue -= n;
    }
    void FightBack(CCreature *target)
    {

    }
};
class CDragon: public CCreature
{
private:

public:
    CDragon()
    {}
    ~CDragon()
    {}
    void Attack(CWolf *pWolf)
    {
        //实现攻击动作的代码
        pWolf->Hurt(nPower);
        pWolf->FightBack(this);
    }
    void Attack(CGhost *pGhost)
    {
        //实现攻击动作的代码
        pGhost->Hurt(nPower);
        pGhost->FightBack(this);
    }
    ////其他Attack略
    void Hurt(int dam)
    {
        //实现受伤动作的代码
        nLifeValue -= dam;
    }
    void FightBack(CWolf *pWolf)
    {
        //反击动作
        pWolf->Hurt(nPower/2);
    }
    //其他FightBack略
protected:

};
//由此看出，有n种怪物时，CDragon类中就会有n种Attack成员函数，以及n个FightBack成员函数，对于其他类亦是如此
//如果游戏版本升级，增加了新的怪物，程序改动极大，所有的类都需要增加两个函数
// void Attack(CThunderBird *pThunderBird);
// void FightBack(CThunderBird *pThunderBird)
#else//多态的实现方法
class CCreature
{
protected:
    int nLifeValue, nPower;
public:
    virtual void Attack(CCreature *pCreature)
    {}
    virtual void Hurt(int damage)
    {}
    virtual void FightBack(CCreature *pCreature)
    {}
};//基类只有一个Attack成员函数和一个Hurt成员函数和一个FightBack成员函数；所有派生类也是这样
//派生类Dragon为例子
class CDragon: public CCreature
{
public:
    virtual void Attack(CCreature *pCreature)
    {
        //攻击动作代码
        //下面体现多态
        pCreature->Hurt(nPower);//被龙打的怪掉血
        pCreature->FightBack(this);//龙要受到被打的怪的反击
    }
    virtual void Hurt(int damage)
    {
        //受伤动作
        nLifeValue -= damage;
    }
    virtual void FightBack(CCreature *pCreature)
    {
        //反击动作
        //下面体现多态
        pCreature->Hurt(nPower/2);//龙自己被打，反击打龙的怪
    }
};
//以下类者均为CDragon类的copy
class CWolf: public CCreature
{
public:
    virtual void Attack(CCreature *pCreature)
    {
        //攻击动作代码
        //下面体现多态
        pCreature->Hurt(nPower);//被龙打的怪掉血
        pCreature->FightBack(this);//龙要受到被打的怪的反击
    }
    virtual void Hurt(int damage)
    {
        //受伤动作
        nLifeValue -= damage;
    }
    virtual void FightBack(CCreature *pCreature)
    {
        //反击动作
        //下面体现多态
        pCreature->Hurt(nPower / 2);//龙自己被打，反击打龙的怪
    }
};
class CGhost: public CCreature
{
public:
    virtual void Attack(CCreature *pCreature)
    {
        //攻击动作代码
        //下面体现多态
        pCreature->Hurt(nPower);//被龙打的怪掉血
        pCreature->FightBack(this);//龙要受到被打的怪的反击
    }
    virtual void Hurt(int damage)
    {
        //受伤动作
        nLifeValue -= damage;
    }
    virtual void FightBack(CCreature *pCreature)
    {
        //反击动作
        //下面体现多态
        pCreature->Hurt(nPower / 2);//龙自己被打，反击打龙的怪
    }
};
class CThunderBird: public CCreature
{
public:
    virtual void Attack(CCreature *pCreature)
    {
        //攻击动作代码
        //下面体现多态
        pCreature->Hurt(nPower);//被龙打的怪掉血
        pCreature->FightBack(this);//龙要受到被打的怪的反击
    }
    virtual void Hurt(int damage)
    {
        //受伤动作
        nLifeValue -= damage;
    }
    virtual void FightBack(CCreature *pCreature)
    {
        //反击动作
        //下面体现多态
        pCreature->Hurt(nPower / 2);//龙自己被打，反击打龙的怪
    }
};
//如果游戏版本升级，增加了新的怪物雷鸟,只需要编写新类CThunderBird,以前写的类可以原封不动，工作量极小
CDragon Dragon;
CWolf Wolf;
CGhost Ghost;
CThunderBird Bird;
int main(int argc, char *argv[])
{
    Dragon.Attack(&Wolf);//(1)
    Dragon.Attack(&Ghost);//(2)
    Dragon.Attack(&Bird);//(3)
    //根据多态规则
    //上面的(1)(2)(3)进入到CDragon::Attack函数后分别调用
    //CWolf::Hurt
    //CGhost::Hurt
    //CBird::Hurt
    //这就实现了多态
    return 0;
}
#endif

