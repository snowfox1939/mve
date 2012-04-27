/*
 * A triangle mesh representation.
 * Written by Simon Fuhrmann.
 */

#ifndef MVE_TRIANGLE_MESH_HEADER
#define MVE_TRIANGLE_MESH_HEADER

#include <vector>

#include "math/vector.h"
#include "util/refptr.h"

#include "defines.h"

MVE_NAMESPACE_BEGIN

/**
 * Triangle mesh representation.
 * The triangle mesh holds a list of vertices,
 * per-vertex normals, colors, and confidences, a list
 * of vertex indices for the faces and per-face normals.
 */
class TriangleMesh
{
public:
    typedef util::RefPtr<TriangleMesh> Ptr;
    typedef util::RefPtr<TriangleMesh const> ConstPtr;

    typedef unsigned int VertexID;
    typedef std::vector<math::Vec3f> VertexList;
    typedef std::vector<math::Vec3f> NormalList;
    typedef std::vector<math::Vec4f> ColorList;
    typedef std::vector<math::Vec2f> TexCoordList;
    typedef std::vector<VertexID> FaceList;
    typedef std::vector<float> ConfidenceList;

    typedef std::vector<bool> DeleteList;

protected:
    VertexList vertices;
    NormalList vertex_normals;
    ColorList vertex_colors;
    ConfidenceList vertex_confidences;
    TexCoordList vertex_texcoords;

    FaceList faces;
    NormalList face_normals;
    ColorList face_colors;

protected:
    TriangleMesh (void);

public:
    ~TriangleMesh (void);
    static Ptr create (void);
    static Ptr create (TriangleMesh::ConstPtr other);

    /** Returns the mesh vertices. */
    VertexList const& get_vertices (void) const;
    /** Returns the vertex normals. */
    NormalList const& get_vertex_normals (void) const;
    /** Returns the vertex colors. */
    ColorList const& get_vertex_colors (void) const;
    /** Returns the vertex confidences. */
    ConfidenceList const& get_vertex_confidences (void) const;
    /** Returns the vectex texture coordinates. */
    TexCoordList const& get_vertex_texcoords (void) const;
    /** Returns the triangle indices. */
    FaceList const& get_faces (void) const;
    /** Returns the face normals. */
    NormalList const& get_face_normals (void) const;
    /** Returns the face colors. */
    ColorList const& get_face_colors (void) const;

    /** Returns the mesh vertices. */
    VertexList& get_vertices (void);
    /** Returns the vertex normals. */
    NormalList& get_vertex_normals (void);
    /** Returns the vertex colors. */
    ColorList& get_vertex_colors (void);
    /** Returns the vertex confidences. */
    ConfidenceList& get_vertex_confidences (void);
    /** Returns the vectex texture coordinates. */
    TexCoordList& get_vertex_texcoords (void);
    /** Returns the triangle indices. */
    FaceList& get_faces (void);
    /** Returns the face normals. */
    NormalList& get_face_normals (void);
    /** Returns the face colors. */
    ColorList& get_face_colors (void);

    /** Returns true if colors and vertex amount are equal. */
    bool has_vertex_colors (void) const;
    /** Returns true if confidence amount and vertex amount are equal. */
    bool has_vertex_confidences (void) const;
    /** Returns true if vertex normals and vertex amount are equal. */
    bool has_vertex_normals (void) const;
    /** Returns true if face normals and face amount are equal. */
    bool has_face_normals (void) const;
    /** Returns true if face colors and face amount are equal. */
    bool has_face_colors (void) const;

    /** Recalculates normals if normal amount is inconsistent. */
    void ensure_normals (bool face = true, bool vertex = true);
    /** Recalculates face and/or vertex normals. */
    void recalc_normals (bool face = true, bool vertex = true);

    /** Clears all mesh data. */
    void clear (void);
    /** Clears mesh normal data. */
    void clear_normals (void);

    /**
     * Deletes marked vertices and related attributes if available.
     * Note that this does not change face data.
     */
    void delete_vertices (DeleteList const& dlist);

    /** Returns the memory consumption in bytes. */
    std::size_t get_byte_size (void) const;
};

/* ---------------------------------------------------------------- */

inline
TriangleMesh::~TriangleMesh (void)
{
}

inline
TriangleMesh::TriangleMesh (void)
{
}

inline TriangleMesh::Ptr
TriangleMesh::create (void)
{
    return Ptr(new TriangleMesh);
}

inline TriangleMesh::Ptr
TriangleMesh::create (TriangleMesh::ConstPtr other)
{
    return Ptr(new TriangleMesh(*other));
}

inline TriangleMesh::VertexList const&
TriangleMesh::get_vertices (void) const
{
    return this->vertices;
}

inline TriangleMesh::NormalList const&
TriangleMesh::get_vertex_normals (void) const
{
    return this->vertex_normals;
}

inline TriangleMesh::ColorList const&
TriangleMesh::get_vertex_colors (void) const
{
    return this->vertex_colors;
}

inline TriangleMesh::ConfidenceList const&
TriangleMesh::get_vertex_confidences (void) const
{
    return this->vertex_confidences;
}

inline TriangleMesh::TexCoordList const&
TriangleMesh::get_vertex_texcoords (void) const
{
    return this->vertex_texcoords;
}

inline TriangleMesh::FaceList const&
TriangleMesh::get_faces (void) const
{
    return this->faces;
}

inline TriangleMesh::NormalList const&
TriangleMesh::get_face_normals (void) const
{
    return this->face_normals;
}

inline TriangleMesh::ColorList const&
TriangleMesh::get_face_colors (void) const
{
    return this->face_colors;
}

inline TriangleMesh::VertexList&
TriangleMesh::get_vertices (void)
{
    return this->vertices;
}

inline TriangleMesh::NormalList&
TriangleMesh::get_vertex_normals (void)
{
    return this->vertex_normals;
}

inline TriangleMesh::ColorList&
TriangleMesh::get_vertex_colors (void)
{
    return this->vertex_colors;
}

inline TriangleMesh::ConfidenceList&
TriangleMesh::get_vertex_confidences (void)
{
    return this->vertex_confidences;
}

inline TriangleMesh::TexCoordList&
TriangleMesh::get_vertex_texcoords (void)
{
    return this->vertex_texcoords;
}

inline TriangleMesh::FaceList&
TriangleMesh::get_faces (void)
{
    return this->faces;
}

inline TriangleMesh::NormalList&
TriangleMesh::get_face_normals (void)
{
    return this->face_normals;
}

inline TriangleMesh::ColorList&
TriangleMesh::get_face_colors (void)
{
    return this->face_colors;
}

inline void
TriangleMesh::clear_normals (void)
{
    this->vertex_normals.clear();
    this->face_normals.clear();
}

inline void
TriangleMesh::clear (void)
{
    this->vertices.clear();
    this->faces.clear();
    this->face_normals.clear();
    this->vertex_normals.clear();
}

inline bool
TriangleMesh::has_vertex_colors (void) const
{
    return this->vertex_colors.size() == this->vertices.size();
}

inline bool
TriangleMesh::has_vertex_confidences (void) const
{
    return this->vertex_confidences.size() == this->vertices.size();
}

inline bool
TriangleMesh::has_vertex_normals (void) const
{
    return this->vertex_normals.size() == this->vertices.size();
}

inline bool
TriangleMesh::has_face_normals (void) const
{
    return this->faces.size() == this->face_normals.size() * 3;
}

inline bool
TriangleMesh::has_face_colors (void) const
{
    return this->faces.size() == this->face_colors.size() * 3;
}

MVE_NAMESPACE_END

#endif /* MVE_TRIANGLE_MESH_HEADER */