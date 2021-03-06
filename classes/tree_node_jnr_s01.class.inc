<?php
// *****************************************************************************
// Copyright 2003-2006 by A J Marston <http://www.tonymarston.net>
// *****************************************************************************
require_once 'tree_node.class.inc';
class tree_node_jnr_s01 extends tree_node
{
    // ****************************************************************************
    // This subtype is for script: tree_node_jnr_popup.php
    // ****************************************************************************
    function _cm_post_getData ($rowdata, &$where)
    // perform custom processing after database record(s) are retrieved.
    // NOTE: $where is passed BY REFERENCE so that it may be modified
    {
        // remove code added in function pre_getData()
        $where = str_replace(" AND node_id_snr IS NULL", '', $where);

        return $rowdata;

    } // _cm_post_getData

    // ****************************************************************************
    function _cm_pre_getData ($where, $where_array, $fieldarray=null)
    // perform custom processing before database record(s) are retrieved.
    // (WHERE is supplied in two formats - string and array)
    // $fieldarray may contain full details of the current record in the parent
    // class, not just its primary key.
    {
        // amend $where to select orphan nodes at the current level
        $where .= " AND node_id_snr IS NULL";

        return $where;

    } // _cm_pre_getData

// ****************************************************************************
} // end class
// ****************************************************************************

?>
