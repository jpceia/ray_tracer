/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cylinder.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:15:33 by jpceia            #+#    #+#             */
/*   Updated: 2022/02/12 14:48:23 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable/Cylinder.hpp"


Cylinder::Cylinder(const CylinderArgs& args) :
    AHittable("Cylinder", args.material),
    _base(args.base),
    _direction(args.direction),
    _radius_sq(args.radius * args.radius),
    _height(args.height)
{
}

// non copyable
Cylinder::Cylinder(const Cylinder& rhs) :
    AHittable(rhs.getName(), rhs.getMaterial()),
    _base(rhs._base),
    _direction(rhs._direction),
    _radius_sq(rhs._radius_sq),
    _height(rhs._height)
{
}

Cylinder& Cylinder::operator=(const Cylinder& rhs)
{
    (void)rhs;
    return *this;
}

bool Cylinder::_valid_hit(float t, float dot_base, float dot_direction) const
{
    float h = dot_base + t * dot_direction;
    return (h >= 0.0f && h <= _height);
}

vec3f Cylinder::_get_normal(const vec3f& p) const
{
    vec3f n = p - _base;
    return n - _direction * rt::dot(n, _direction);
}

/*
 * Checks if a ray hits a cylinder
 * The equation of a cylinder is:
 * 	|(p - p0) x n)| = R
 * 	<p - p0, n> \in [0, height]
 * Substituting p by our ray r(t) = r0 + t * d, t > 0
 * We have a 2nd degree equation
 * R^2 = |(r0 - p0 + t * d) x n|^2 = |(r0 - p0) x n + (d x n) * t|^2
 *     = |d x n|^2 t^2 + 2 * t * <d x n, v x n> + |v x n|^2 
 * with v = r0 - p0
 * 
 * the coeficients of "a * t^2 + b * t + c = 0" are
 * a = |d x n|^2
 * b = 2 * <d x n, v x n>
 * c = |v x n|^2 - R^2
 * 
 * The solution is t = -h +- sqrt(h^2 - c)
 * with h = b / (2 * a)
 * 
 * Regarding the height of the cylinder, we still have
 * <r(t) - p0, n> = <d * t + v, n> = t * <d,n> + <v, n> between 0 and H
 * with v = r0 - p0
 */
bool Cylinder::hit(const Ray3f& ray, const Range& t_rng, HitRecord& rec) const
{
    vec3f v = ray.getOrigin() - _base;
    vec3f d_cross_n = rt::cross(ray.getDirection(), _direction);
    vec3f v_cross_n = rt::cross(v, _direction);
    Deg2eqParams params;
    params.a = d_cross_n.lengthSquared();
    params.b = 2 * rt::dot(d_cross_n, v_cross_n);
    params.c = v_cross_n.lengthSquared() - _radius_sq;

    Range rng;
    if (!deg2eq_solve(params, &rng))
        return false;
    if (rng.min > t_rng.max || rng.max < t_rng.min)
        return false;
    float v_dot_n = rt::dot(v, _direction);
    float d_dot_n = rt::dot(ray.getDirection(), _direction);
    if (rng.min >= t_rng.min && _valid_hit(rng.min, v_dot_n, d_dot_n))
        rec.t = rng.min;
    else if (rng.max <= t_rng.max && _valid_hit(rng.max, v_dot_n, d_dot_n))
        rec.t = rng.max;
    else
        return false;
    rec.p = ray.getPointAt(rec.t);
    rec.normal = _get_normal(rec.p).normalize();;
    return true;
}
