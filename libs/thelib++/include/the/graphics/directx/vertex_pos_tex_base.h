/*
 * include\the\graphics\directx\vertex_pos_tex_base.h
 *
 * Copyright (C) 2013 TheLib Team (http://www.thelib.org/license)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of TheLib, TheLib Team, nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THELIB TEAM AS IS AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THELIB TEAM BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef THE_GRAPHICS_DIRECTX_VERTEX_POS_TEX_BASE_H_INCLUDED
#define THE_GRAPHICS_DIRECTX_VERTEX_POS_TEX_BASE_H_INCLUDED
#if (defined(_MSC_VER) && (_MSC_VER > 1000))
#pragma once
#endif /* (defined(_MSC_VER) && (_MSC_VER > 1000)) */
#if defined(_WIN32) && defined(_MANAGED)
#pragma managed(push, off)
#endif /* defined(_WIN32) && defined(_MANAGED) */

#include "the/config.h"

#ifdef WITH_THE_DIRECTX
#include "the/graphics/directx/vertex_pos_base.h"


namespace the {
namespace graphics {
namespace directx {

    /**
     * Base implementation of a vertex with position and texture coordinates.
     *
     * @tparam P  The type used for storing the position.
     * @tparam PC The type of a single component of the position.
     * @tparam PF The DXGI format for the position.
     * @tparam T  The type used for storing the texture coordinates.
     * @tparam TC The type of a single component of the texture coordinates.
     * @tparam TF The DXGI format for the texture coordinates.
     */
    template<class P, class PC, DXGI_FORMAT PF,
        class T, class TC, DXGI_FORMAT TF>
    struct vertex_pos_tex_base : public vertex_pos_base<P, PC, PF> {

        /** Super class typedef. */
        typedef vertex_pos_base base;

        /** The type used for specifying texture coordinates. */
        typedef TC texcoord_coordinate_type;

        /** The type used for the texture coordinates. */
        typedef T texcoord_type;

#ifdef WITH_THE_DIRECTX11
        /** Input layout description for the vertex type. */
        static const D3D11_INPUT_ELEMENT_DESC d3d11_input_layout[1];
#endif /* WITH_THE_DIRECTX11 */

        /** The DXGI format used for the texture coordinates. */
        static const DXGI_FORMAT texcoord_format;

        /**
         * Assign values of 'rhs' to this object.
         *
         * @param rhs The right hand side operand.
         *
         * @return *this.
         */
        vertex_pos_tex_base& operator =(const vertex_pos_tex_base& rhs);

        /** The texture coordinates of the vertex. */
        texcoord_type texcoords;
    };

} /* end namespace directx */
} /* end namespace graphics */
} /* end namespace the */


#ifdef WITH_THE_DIRECTX11
/*
 * ...::directx::vertex_pos_tex_base<P, PC, PF, T, TC, TF>::d3d11_input_layout
 */
template<class P, class PC, DXGI_FORMAT PF,
    class T, class TC, DXGI_FORMAT TF>
const D3D11_INPUT_ELEMENT_DESC
the::graphics::directx::vertex_pos_tex_base<P, PC, PF, T, TC, TF>::d3d11_input_layout[]
= {
    { "POSITION", 0, position_format, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }
    { "TEXCOORD", 0, texcoord_format, 0, sizeof(position_format), D3D11_INPUT_PER_VERTEX_DATA, 0 }
};
#endif /* WITH_THE_DIRECTX11 */


/*
 * ...::directx::vertex_pos_tex_base<P, PC, PF, T, TC, TF>::texcoord_format
 */
template<class P, class PC, DXGI_FORMAT PF,
    class T, class TC, DXGI_FORMAT TF>
const DXGI_FORMAT
the::graphics::directx::vertex_pos_tex_base<P, PC, PF, T, TC, TF>::texcoord_format
= TF;


/*
 * the::graphics::directx::vertex_pos_base<P, PC, PF>::operator =
 */
template<class P, class PC, DXGI_FORMAT PF,
    class T, class TC, DXGI_FORMAT TF>
the::graphics::directx::vertex_pos_tex_base<P, PC, PF, T, TC, TF>&
the::graphics::directx::vertex_pos_tex_base<P, PC, PF, T, TC, TF>::operator =(
        const vertex_pos_tex_base& rhs) {
    THE_STACK_TRACE;
    if (this != &rhs) {
        base::operator =(rhs);
        this->texcoords = rhs.texcoords;
    }
    return *this;
}

#endif /* WITH_THE_DIRECTX */

#if defined(_WIN32) && defined(_MANAGED)
#pragma managed(pop)
#endif /* defined(_WIN32) && defined(_MANAGED) */
#endif /* THE_GRAPHICS_DIRECTX_VERTEX_POS_TEX_BASE_H_INCLUDED */
