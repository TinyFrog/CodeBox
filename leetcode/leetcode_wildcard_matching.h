//
//  leetcode_wildcard_matching.h
//  Hacker
//
//  Created by Shaobo Sun on 10/11/13.
//  Copyright (c) 2013 Shaobo. All rights reserved.
//

#ifndef Hacker_leetcode_wildcard_matching_h
#define Hacker_leetcode_wildcard_matching_h

bool isMatch_core(const char *s, const char *p){
    if(*p == '\0' && *s == '\0'){
        return true;
    }else if(*p == '\0' && *s != '\0'){
        return false;
    }else if(*p != '\0'  && *s == '\0'){
        // *p != '\0'  && *s == '\0'
        const char* end_detector = p;
        end_detector++;
        if( *p == '*' ){
            if(*end_detector != '\0'){
                return false;
            }else{
                return true;
            }
        }else{
            return false;
        }
    }
    
    if(*p == '?'){
        return isMatch_core(++s, ++p);
    }else if(*p == '*'){
        // it means the letter before * matches letter in s, keep iterating down in s until letter is different
        const char* current_s = s;
        while(*s == *current_s){
            s++;
        }
        const char* next_p = p;
        next_p++;
        return isMatch_core(current_s, next_p) || isMatch_core(s, next_p);
    }else{
        // a-z
        if(*s == *p){
            return isMatch_core(++s, ++p);
        }else{
            return false;
        }
        
    }
}


#endif
