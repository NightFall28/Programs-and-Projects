//CLASS IMPLEMENTED: statistician (see stat.h for documentation) 

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string.h> 
#include "CSc212 Assignment 1.h"
using namespace std;
namespace main_savitch_2C {


    statistician::statistician()
    {
        count = 0;
        total = 0;
        tinyest = 0;
        largest = 0;
    }

    void statistician::next(double r)
    {
        if (count == 0) {
            tinyest = r;
            largest = r;
            count++;
            total = r;
        }
        else {
            if (r < tinyest)
                tinyest = r;
            else if (r > largest)
                largest = r;
            total += r;
            count++;
        }
    }

    int statistician::length() const
    {
        return count;
    }

    void statistician::reset()
    {
        if (count == 0)
            return;

        count = 0;
        total = 0;
        tinyest = 0;
        largest = 0;

    }

    double statistician::minimum() const
    {
        if (count > 0)
            return tinyest;
        return 0;
    }

    double statistician::maximum() const
    {
        if (count > 0)
            return largest;
        return 0;
    }

    double statistician::sum() const
    {
        if (count == 0)
            return 0;
        return total;
    }

    double statistician::mean() const
    {
        if (count == 0)
            return 0;
        return (total / count);
    }

    statistician operator +(const statistician& s1, const statistician& s2)
    {
        if (s1.length() == 0) {
            return statistician(s2);
        }

        else if (s2.length() == 0) {
            return statistician(s1);
        }

        statistician s3 = statistician();
        s3.count = s1.count + s2.count;
        s3.total = s1.total + s2.total;

        //find s3.tinyest:
        if (s1.tinyest < s2.tinyest || s1.tinyest == s2.tinyest) {
            s3.tinyest = s1.tinyest;
        }
        else {
            s3.tinyest = s2.tinyest;
        }

        //find s3.largest:
        if (s1.largest > s2.largest || s1.largest == s2.largest) {
            s3.largest = s1.largest;
        }
        else {
            s3.largest = s2.largest;
        }

        
            return s3;

    }

    statistician operator *(double scale, const statistician& s)
    {
        if (s.length() == 0)
            return s;
   
        statistician mod_s = statistician();
        mod_s.count = s.count;
        mod_s.total = s.total * scale;

        //positive scale
        if (scale > 0) {
            mod_s.largest = s.largest * scale;
            mod_s.tinyest = s.tinyest * scale;
        }
        
        //negative scale
        else {
            mod_s.largest = s.tinyest * scale;
            mod_s.tinyest = s.largest * scale;
        }

        return mod_s;
    }

    bool operator ==(const statistician& s1, const statistician& s2)
    {
        if (s1.length() == 0 && s2.length() == 0)
            return true;

        if (s1.length() == s2.length() && s1.sum() == s2.sum() && s1.mean() == s2.mean()
            && s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum()) {

            return true;
        }
        else
            return false;
    }
}
