//
// Created by noam on 1/16/19.
//

#ifndef EVEN2_ICACHEMANAGER_H
#define EVEN2_ICACHEMANAGER_H

template<class key, class value>
class ICacheManager {

public:

    virtual bool contains(key problem) = 0;

    virtual value getSolution(key problem) = 0;

    virtual void saveSolution(key problem, value solution) = 0;

    virtual ~ICacheManager() = default; //use save all probs and sol here.

};


#endif //EVEN2_ICACHEMANAGER_H
