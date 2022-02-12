/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cylinder.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:29:37 by jpceia            #+#    #+#             */
/*   Updated: 2022/02/12 13:44:42 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CYLINDER_HPP
# define CYLINDER_HPP

# include "AHittable.hpp"

//struct Range;

struct CylinderArgs
{
    vec3f base;
    vec3f direction;
    float radius;
    float height;
    Material material;
};

class Cylinder : public AHittable
{
private:
    const vec3f _base;
    const vec3f _direction;
    const float _radius;
    const float _height;

    // non-assignable
    Cylinder& operator=(const Cylinder& rhs);

    bool _valid_hit(float t, float dot_base, float dot_direction) const;

public:
    Cylinder(const CylinderArgs& args);
    Cylinder(const Cylinder& rhs);
    
    virtual ~Cylinder() {}

    bool hit(const Ray3f& ray, const Range& t_rng, HitRecord& rec) const;
};

# endif
