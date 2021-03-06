<?php
// *****************************************************************************
// Copyright 2003-2006 by A J Marston <http://www.tonymarston.net>
// *****************************************************************************
require_once 'std.table.class.inc';
class tree_level extends Default_Table
{
    // ****************************************************************************
    function tree_level ()
    {
        // save directory name of current script
        $this->dirname   = dirname(__file__);

        $this->dbms_engine = $GLOBALS['dbms'];
        $this->dbname      = 'tuphamtest';
        $this->tablename   = 'tree_level';

        // call this method to get original field specifications
        // (note that they may be modified at runtime)
        $this->fieldspec = $this->getFieldSpec_original();

    } // tree_level

    // ****************************************************************************
    function _cm_getInitialData ($fieldarray)
    // Perform custom processing for the getInitialData method.
    // $fieldarray contains data from the initial $where clause.
    {
        if (!empty($fieldarray['tree_type_id'])) {
            // get next available number for tree_level_id
            $where = "tree_type_id='{$fieldarray['tree_type_id']}'";
            $query = "SELECT max(tree_level_id) FROM $this->tablename WHERE $where";
            $count = $this->getCount($query);
            $fieldarray['tree_level_id']  = $count + 1;
            $fieldarray['tree_level_seq'] = $count + 1;
        } // if

        // set these fields to 'noedit' (read only)
        $this->fieldspec['tree_level_id']['noedit']  = 'y';
        $this->fieldspec['tree_level_seq']['noedit'] = 'y';

        return $fieldarray;

    } // _cm_getInitialData

    // ****************************************************************************
    function _cm_getValRep ($item = '')
    // get Value/Representation list as an associative array.
    {
        $array = array();

        if ($item == 'tree_level_id') {
            // get data from the database
            $this->sql_select     = 'tree_level_id, tree_level_desc';
            $this->sql_orderby    = 'tree_level_seq';
            $this->sql_ordery_seq = 'asc';
            $data = $this->getData(null);

            // convert each row into 'id=desc' in the output array
            foreach ($data as $row => $rowdata) {
                $rowvalues = array_values($rowdata);
                $array[$rowvalues[0]] = $rowvalues[1];
            } // foreach

            return $array;

        } // if

        return $array;

    } // _cm_getValRep

    // ****************************************************************************
    function _cm_pre_getData ($where, $where_array, $fieldarray=null)
    // perform custom processing before database record(s) are retrieved.
    // (WHERE is supplied in two formats - string and array)
    // $fieldarray may contain full details of the current record in the parent
    // class, not just its primary key.
    {
        // remove any tablename which qualifies a fieldname
        $where = unqualifyWhere($where);

        // convert 'node_id_snr=' to 'node_id=;
        $where = str_replace('node_id_snr=', 'node_id=', $where);

        // find out if $selection is for TREE_NODE table
        if (preg_match('/(node_id=)/', $where)) {
            // yes - convert to TREE_LEVEL table
            require_once 'classes/tree_node.class.inc';
            $dbobject =& singleton::getInstance('tree_node');

            // read data from TREE_NODE table
            $tree_node_data = $dbobject->getData($where);
            if ($dbobject->errors) {
                $this->errors = $dbobject->errors;
                return $where;
            } // if

            // get data from foreign table TREE_LEVEL
            $tree_type_id  = $tree_node_data[0]['tree_type_id'];
            $tree_level_id = $tree_node_data[0]['tree_level_id'];
            $where2        = "tree_type_id='$tree_type_id' AND tree_level_id='$tree_level_id'";
            $tree_level_data = $this->getData($where2);

            // get data for TREE_LEVEL which is one level lower
            $tree_level_seq = $tree_level_data[0]['tree_level_seq'] + 1;
            $where2         = "tree_type_id='$tree_type_id' AND tree_level_seq='$tree_level_seq'";
            $this->checkPrimaryKey = false;
            $tree_level_data = $this->getData($where2);

            // if ($this->errors) return($this->errors);
            if ($this->numrows <> 1) {
                // 'This is the lowest level - no children allowed'
                $this->errors[] = getLanguageText('e0003');
                return $where;
            } else {
                $where = array2where($tree_level_data[0], $this->getPkeyNames());
            } // if

            unset($dbobject);
        } // if

        if (empty($this->sql_select)) {
            // include columns from foreign table
            $this->sql_select = 'tree_level.*, tree_type.tree_type_desc';
            $this->sql_from   = 'tree_level '
                              . 'LEFT JOIN tree_type ON (tree_type.tree_type_id=tree_level.tree_type_id)';
        } // if

        return $where;

    } // _cm_pre_getData

// ****************************************************************************
} // end class
// ****************************************************************************

?>
