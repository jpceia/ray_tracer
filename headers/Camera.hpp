/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 01:32:16 by jpceia            #+#    #+#             */
/*   Updated: 2022/01/22 04:29:59 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_HPP
# define CAMERA_HPP

# include "Vector.hpp"
# include "Referencial.hpp"

struct CameraArgs
{
	ReferencialArgs ref;
	float fov;
};

class Camera
{
private:
	Referencial _ref;
	float  _fov;
    float _view_width;


public:
    Camera();
    Camera(const CameraArgs& args);
    Camera(const Camera& rhs);
    Camera& operator=(const Camera& rhs);
    virtual ~Camera();

    // Getters
    vec3f getPosition() const;
    vec3f getDirection() const;
    vec3f getUp() const;
    vec3f getRight() const;
    float getFov() const;
    float getViewWidth() const;
};

#endif
