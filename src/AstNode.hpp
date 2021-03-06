/*
 * SQLassie - database firewall
 * Copyright (C) 2011 Brandon Skari <brandon.skari@gmail.com>
 *
 * This file is part of SQLassie.
 *
 * SQLassie is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SQLassie is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SQLassie. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SRC_ASTNODE_HPP_
#define SRC_ASTNODE_HPP_

#include <vector>
#include <string>
#include <iosfwd>

#include "warnUnusedResult.h"

/**
 * Abstract syntax tree nodes generated by the parser.
 * @author Brandon Skari
 * @date December 9 2010
 **/

class AstNode
{
public:
    /**
     * Default constructor.
     * @param name The name of this node.
     */
    explicit AstNode(const std::string& name);

    virtual ~AstNode();

    /**
     * Adds a child to this AstNode.
     */
    void addChild(const AstNode* child);

    /**
     * Returns the name of this node.
     */
    const std::string& getName() const WARN_UNUSED_RESULT;

    /**
     * Prints out this node and its children.
     */
    virtual void print(
        std::ostream& out,
        const int depth = 0,
        const char indent = ' '
    ) const;

protected:
    /**
     * Returns a deep copy of this node.
     */
    virtual AstNode* copy() const WARN_UNUSED_RESULT;

    /**
     * Calls print() on this node's childen.
     */
    void printChildren(
        std::ostream& out,
        const int depth,
        const char indent
    ) const;

    /**
     * Adds a copy of each of the children to the provided node.
     * Used by inheriting classes' copy methods.
     * @param node The node to add the copies of the children to
     */
    void addCopyOfChildren(AstNode* node) const;
    std::string name_;
    std::vector<const AstNode*> children_;

private:
    // Prevent compiler warnings; shouldn't be calling this anyway
    AstNode& operator=(const AstNode& rhs);
    AstNode(const AstNode& rhs);
};

std::ostream& operator<<(std::ostream& out, const AstNode& node);

#endif  // SRC_ASTNODE_HPP_
