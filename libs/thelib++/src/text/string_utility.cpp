/*
 * the/text/string_utility.cpp
 *
 * Copyright (c) 2012, TheLib Team (http://www.thelib.org/license)
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

#include "the/string.h"
#include "the/text/string_utility.h"
#include "the/invalid_operation_exception.h"


/*
 * the::text::string_utility::empty_astring
 */
const the::astring the::text::string_utility::empty_astring("");


/*
 * the::text::string_utility::empty_wstring
 */
const the::wstring the::text::string_utility::empty_wstring(L"");


/*
 * the::text::string_utility::string_utility
 */
the::text::string_utility::string_utility(void) {
    throw the::invalid_operation_exception("string_utility::ctor",
        __FILE__, __LINE__);
}


/*
 * the::text::string_utility::string_utility
 */
the::text::string_utility::string_utility(
        const the::text::string_utility& src) {
    throw the::invalid_operation_exception("string_utility::ctor",
        __FILE__, __LINE__);
}


/*
 * the::text::string_utility::~string_utility
 */
the::text::string_utility::~string_utility(void) {
    throw the::invalid_operation_exception("string_utility::dtor",
        __FILE__, __LINE__);
}
