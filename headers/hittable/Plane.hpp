/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plane.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:30:15 by jpceia            #+#    #+#             */
/*   Updated: 2022/02/12 15:17:10 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_HPP
# define PLANE_HPP

# include "APlaneSurface.hpp"

struct PlaneArgs
{
    vec3f point;
    vec3f normal;
    Material material;
};

class Plane : public APlaneSurface
{
private:
    // non-assignable
    Plane& operator=(const Plane& rhs) { (void)rhs; return *this; };

    bool _check_boundary(const vec3f& p) const;

public:
    Plane(const Plane& rhs);
    Plane(const PlaneArgs& args);
    virtual ~Plane() {}
};

#endif
