<?php
$structure['xsl_file'] = 'std.filepicker.list1.xsl';

$structure['tables']['main'] = 'file';

$structure['main']['columns'][] = array('width' => '40%');
$structure['main']['columns'][] = array('width' => '10%');

$structure['main']['fields'][] = array('file' => 'File Name', 'nosort' => 'y');
$structure['main']['fields'][] = array('image' => 'Image', 'nosort' => 'y',
                                       'imagewidth' => 75,
                                       'imageheight' => 95);

?>