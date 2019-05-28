/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  17/03/2016 05:31:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kr.borowiec@gmail.com,
 *        Company:
 *
 * =====================================================================================
 */
#include <map>
#include <tuple>
#include <memory>
#include <vector>
#include <utility>
#include <iostream>

struct Cross { };
struct Widmo { };
struct Konst { };


struct RxId
{
    RxId(int id): id_(id){}
    int id_;
};

struct TxId
{
    TxId(int id): id_(id){}

    int id_;
};

enum class Mode : std::uint8_t
{
    RTM, RMT, TMR
};


template<typename T>
class BistGraphData
{
  public:


    void add(RxId Rx, TxId Tx, Mode mm, const std::shared_ptr<T>& value)
    {
        int r = Rx.id_;
        int t = Tx.id_;
        int m = static_cast<int>(mm);

        auto keyRTM = std::make_tuple(r,t,m);
        auto keyRMT = std::make_tuple(r,m,t);
        auto keyTMR = std::make_tuple(t,m,r);

        mapRTM_[keyRTM] = value;
        mapRMT_[keyRMT] = value;
        mapTMR_[keyTMR] = value;
    }

    std::vector<std::shared_ptr<T> > getForMode(Mode mode, const std::vector<std::tuple<int,int,int> >& selected)
    {
        const Map& m = getMap(mode);

        std::vector<std::shared_ptr<T>> out;

        for(const auto& s : selected)
        {
            auto it = m.find(s) ;
            if (it != m.end())
            {
                out.push_back(it.second);
            }
            else{
                //FATAL EXCEPTION
            }
        }
        return out;
    }

  private:
   using Map = std::map<std::tuple<uint8_t,uint8_t,uint8_t>, std::shared_ptr<T> >;
   const Map& getMap(Mode mode)
   {
        switch(mode)
        {
        case Mode::RTM : return mapRTM_;
        default: return mapRTM_;
        }
   }

  private:
    std::map<std::tuple<int,int,int>, std::shared_ptr<T> >mapRTM_;
    std::map<std::tuple<int,int,int>, std::shared_ptr<T> >mapRMT_;
    std::map<std::tuple<int,int,int>, std::shared_ptr<T> >mapTMR_;
};


struct GraphData
{
    template<typename ...Ts>
    void addCrossData(Ts&& ...ts)
    {
        crossData_.add(std::forward<Ts>(ts)...);
    }

    template<typename ...Ts>
    void addWidmoData(Ts&& ...ts)
    {
        widmoData_.add(std::forward<Ts>(ts)...);
    }

    template<typename ...Ts>
    void addKonstData(Ts&& ...ts)
    {
        konstData_.add(std::forward<Ts>(ts)...);
    }

private:
    BistGraphData<Cross> crossData_;
    BistGraphData<Widmo> widmoData_;
    BistGraphData<Konst> konstData_;
};

struct LinearData
{
    using ValueT = int;
    std::map<int /* figure */ , ValueT>;
};

using namespace std;

int main()
{

    RxId r(1);
    TxId t(2);
    Mode m = Mode::RTM;

    GraphData g;
   
    auto cp = std::make_shared<Cross>();
    g.addCrossData(r,t,m, cp);
    
    auto kp = std::make_shared<Konst>();
    g.addKonstData(r,t, m, kp);

    cout << "hello " << endl;

    return 0;
}
