/*
 * link `target/x86_64-pc-windows-gnu/debug/deps/xpsprint.o`.
 */
extern crate windows_result;
extern crate windows_strings;

use windows_result::*;
use windows_strings::*;

const S_OK: HRESULT = HRESULT(0);

struct IXpsPrintJob;
struct IXpsPrintJobStream;

#[no_mangle]
pub extern "C" fn StartXpsPrintJob(
    _printer_name: /*L*/PCWSTR, // 32bit ptr variant not in crate yet.
    _job_name:          PCWSTR,
    _output_filename:   PCWSTR,
    _progress_event:    u64,
    _completion_event:  u64,
    _printable_pages:   &u8,
    _printable_pages_count: u32,
    _xps_printjob:      &IXpsPrintJob,
    _doc_stream:        &IXpsPrintJobStream,
    _ticket_stream:     &IXpsPrintJobStream,
) -> HRESULT {
    // https://learn.microsoft.com/en-us/windows/win32/api/xpsprint/nf-xpsprint-startxpsprintjob
    //unsafe {
    //    println!("{:?}", printer_name.to_string());
    //};
    S_OK
}
